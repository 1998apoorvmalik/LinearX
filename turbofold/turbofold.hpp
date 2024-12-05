#ifndef TURBOFOLD
#define TURBOFOLD

#include <vector>

#include "./../linear_align/linear_align.hpp"
#include "./../partition/partition.hpp"
#include "./utility.hpp"

class TurboAlign;
class TurboPartition;

class LinearTurboFold {
    const static int min_beam_size = 50;

   private:
    MultiSeq *multi_seq;
    EnergyModel energy_model;

    std::vector<float> seq_identities;  // contains pairwise sequence identities for all k^2 sequence pairs
    std::vector<TurboPartition> pfs;    // contains partition function objects for k sequences
    std::vector<TurboAlign> alns;       // contains alignment objects for all k^2 sequence pairs

   public:
    // const EnergyParamsType energy_params;
    const int num_itr;  // number of iterations
    const bool use_lazy_outside;
    const bool use_prev_outside_score;
    const bool shrink_beam;
    const VerboseState verbose_state;

    int itr;                                                                 // current iteration
    int beam_size = 100;                                                     // current beam size for beam pruning
    std::vector<std::vector<std::unordered_map<int, double>>> extinf_cache;  // cache for extrinsic information

    LinearTurboFold(MultiSeq *multi_seq, const EnergyParamsType energy_params, const int num_itr,
                    const bool use_lazy_outside, const bool use_prev_outside_score, const bool shrink_beam,
                    const VerboseState verbose_state)
        : multi_seq(multi_seq),
          energy_model(energy_params),
          num_itr(num_itr),
          use_lazy_outside(use_lazy_outside),
          use_prev_outside_score(use_prev_outside_score),
          shrink_beam(shrink_beam),
          verbose_state(verbose_state) {
        size_t num_pairs = (multi_seq->size() * (multi_seq->size() - 1)) / 2;

        // reserve space for sequence pairs and sequence identities
        alns.reserve(num_pairs);
        seq_identities.reserve(num_pairs);

        // reserve space extrinsic info cache
        extinf_cache.resize(multi_seq->size());

        for (int i = 0; i < multi_seq->size(); i++) {
            multi_seq->at(i).k_id = i;  // set k_id for each sequence
            pfs.emplace_back(this, &(multi_seq->at(i)), energy_model,
                             use_prev_outside_score);  // better than pfs.push_back(),
                                                       // creates Partition object directly
                                                       // inside the container

            // enumerate all possible k^2 sequence pairs and create LinearAlign objects
            for (int j = i + 1; j < multi_seq->size(); j++) {
                alns.emplace_back(this, &(multi_seq->at(i)), &(multi_seq->at(j)), use_prev_outside_score);
                seq_identities.push_back(0.0f);
            }

            // initialize extrinsic info cache for each sequence
            extinf_cache[i].resize(multi_seq->at(i).length());
        }
    }

    int get_seq_pair_index(const int k1, const int k2);
    double get_extrinsic_info(const Seq &x, int i, int j);
    void reset_extinf_cache();
    void run();
};

class TurboPartition final : public Partition {
   private:
    LinearTurboFold *turbofold;
    PartitionFunctionBeam pfb;
    bool use_prev_outside_score;

   public:
    friend class LinearTurboFold;

    ProbAccm prob_accm;

    TurboPartition(LinearTurboFold *turbofold, const Seq *sequence, EnergyModel &energy_model,
                   bool use_prev_outside_score, bool allow_sharp_turn = false, bool verbose_output = true)
        : Partition(sequence, energy_model, InsideMode::PARTITION, allow_sharp_turn, verbose_output),
          turbofold(turbofold),
          pfb(use_prev_outside_score ? sequence->length() : 0),
          use_prev_outside_score(use_prev_outside_score) {}

    void get_incoming_edges_state(const int i, const int j, const StateType type,
                                  std::vector<HEdge> &incoming_hedges) override;
    double beam_prune(StateType type, int j, int beam_size);
    bool check_state(const StateType type, const int i, const int j) override;
    void compute_inside(int beam_size = 100) override;
    void calc_prob_accm();
};

class TurboAlign final : public LinearAlign {
   private:
    LinearTurboFold *turbofold;
    AlignBeam ab;
    bool use_prev_outside_score;

   public:
    friend class LinearTurboFold;

    TurboAlign(LinearTurboFold *turbofold, const Seq *sequence1, const Seq *sequence2, bool use_prev_outside_score,
               bool verbose = false, double alpha1 = 1.0, double alpha2 = 1.0, double alpha3 = 1.0)
        : LinearAlign(sequence1, sequence2, verbose, alpha1, alpha2, alpha3),
          turbofold(turbofold),
          ab(use_prev_outside_score ? sequence1->length() + sequence2->length() : 0),
          use_prev_outside_score(use_prev_outside_score) {}

    double beam_prune(std::unordered_map<std::pair<int, int>, HState, PairHash> &beamstep, HStateType h,
                      int beam_size) override;
};

#endif  // TURBOFOLD
