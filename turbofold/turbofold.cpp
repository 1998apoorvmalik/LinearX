#include "turbofold.hpp"

int LinearTurboFold::get_seq_pair_index(const int k1, const int k2) {
    // ensure the indices are within bounds
    if (k1 >= multi_seq->size() || k2 >= multi_seq->size()) {
        throw std::out_of_range("Seq index k out of range");
    }

    // ensure k1 != k2 and k1 < k2 by swapping if necessary
    int a = k1, b = k2;
    if (k1 == k2) {
        throw std::invalid_argument("k1 and k2 must be different");
    }
    if (k1 > k2) {
        std::swap(a, b);
    }

    // number of sequences
    int n = multi_seq->size();

    // compute the index using the triangular indexing formula
    int index = a * (2 * n - a - 1) / 2 + (b - a - 1);

    return index;
}

double LinearTurboFold::get_extrinsic_info(const Seq &x, const int i, const int j) {
    if (this->itr == 0) return 0.0;

    const auto it = extinf_cache[x.k_id][j].find(i);
    if (it != extinf_cache[x.k_id][j].end()) {
        return it->second;  // cache lookup
    }

    double output = 0;
    for (const Seq &y : *multi_seq) {
        if (x.k_id == y.k_id) continue;

        const int seq_pair_idx = get_seq_pair_index(x.k_id, y.k_id);
        const double seq_idnty = seq_identities[seq_pair_idx];
        const LinearAlign &aln = alns[seq_pair_idx];
        const TurboPartition &y_pf = pfs.at(y.k_id);

        if (x.k_id == aln.sequence1->k_id) {
            for (const auto &itr1 : aln.coinc_prob[i]) {
                for (const auto &itr2 : aln.coinc_prob[j]) {
                    const int k = itr1.first;
                    const int l = itr2.first;
                    const double aln_prob_ik = itr1.second;
                    const double aln_prob_jl = itr2.second;
                    const double y_bpp_kl = y_pf.get_bpp(k, l);

                    output += (1 - seq_idnty) * y_bpp_kl * aln_prob_ik * aln_prob_jl;
                }
            }
        } else {
            for (const int k : aln.prob_rev_idx[i]) {
                for (const int l : aln.prob_rev_idx[j]) {
                    const double aln_prob_ik = aln.get_bpp(k, i);
                    const double aln_prob_jl = aln.get_bpp(l, j);
                    const double y_bpp_kl = y_pf.get_bpp(k, l);

                    output += (1 - seq_idnty) * y_bpp_kl * aln_prob_ik * aln_prob_jl;
                }
            }
        }
    }

    output = xlog(2 * output);
    extinf_cache[x.k_id][j][i] = output;  // cache the result
    return output;
}

void LinearTurboFold::reset_extinf_cache() {
    for (int k = 0; k < multi_seq->size(); k++) {
        for (int j = 0; j < multi_seq->at(k).length(); j++) {
            extinf_cache[k][j].clear();
        }
    }
}

void LinearTurboFold::run() {
    for (itr = 0; itr <= num_itr; ++itr) {
        // Utility::showProgressBar(itr, num_itr);

        // if (shrink_beam && itr > 1) {
        //     beam_size -= 25;
        //     beam_size = std::max(min_beam_size, beam_size);
        // }

        // align step
        std::cerr << "-------------------------CURRENT ITERATION: " << itr << "-------------------------\n"
                  << "BEAM SIZE: " << beam_size << std::endl;
        if (itr > 0) {
            auto align_start_time = std::chrono::high_resolution_clock::now();
            int align_total_inside_time = 0;
            int align_total_outside_time = 0;
            for (TurboAlign &aln : alns) {
                const int k1 = aln.sequence1->k_id;
                const int k2 = aln.sequence2->k_id;
                const int aln_pair_index = get_seq_pair_index(k1, k2);
                float seq_idnty = seq_identities[aln_pair_index];

                // get the alignments
                aln.reset_beams(use_prev_outside_score ? false : true);
                aln.prob_set1();
                // itr <= 1 ? aln.prob_set1() : aln.prob_set2(seq_idnty);
                if (itr > 0) aln.set_prob_accm(pfs[k1].prob_accm, pfs[k2].prob_accm);
                aln.compute_inside(true, beam_size, verbose_state == VerboseState::DEBUG);
                MultiSeq alignment = aln.get_alignment();
                seq_idnty = alignment.get_seq_identity();    // get the new sequence identity using the new alignment
                seq_identities[aln_pair_index] = seq_idnty;  // store the updated sequence identity

                // if (verbose_state == VerboseState::DEBUG) {
                // std::cout << "Alignment: " << k1 << " " << k2 << std::endl;
                // std::cout << alignment[0].sequence << std::endl;
                // std::cout << alignment[1].sequence << std::endl;
                // aln.print_alpha_beta();
                // std::cout << alignment.get_seq_identity() << std::endl;
                // }

                // compute partition function
                aln.reset_beams(true);
                aln.prob_set2(seq_idnty);
                if (itr > 0) aln.set_prob_accm(pfs[k1].prob_accm, pfs[k2].prob_accm);

                auto align_inside_start_time = std::chrono::high_resolution_clock::now();
                aln.compute_inside(false, beam_size, verbose_state == VerboseState::DEBUG);
                auto align_inside_end_time = std::chrono::high_resolution_clock::now();

                auto align_outside_start_time = std::chrono::high_resolution_clock::now();
                aln.compute_outside(use_lazy_outside, alignment_pruning_threshold,
                                    verbose_state == VerboseState::DEBUG);
                auto align_outside_end_time = std::chrono::high_resolution_clock::now();

                align_total_inside_time += std::chrono::duration_cast<std::chrono::milliseconds>(
                                               align_inside_end_time - align_inside_start_time)
                                               .count();
                align_total_outside_time += std::chrono::duration_cast<std::chrono::milliseconds>(
                                                align_outside_end_time - align_outside_start_time)
                                                .count();

                aln.compute_coincidence_probabilities(verbose_state == VerboseState::DEBUG);
                if (verbose_state == VerboseState::DEBUG) {
                    aln.print_alpha_beta();
                } else if (verbose_state == VerboseState::DETAIL) {
                    aln.dump_coinc_probs("./vb_info/" + std::to_string(itr) + "_aln_" + std::to_string(k1) + "_" +
                                         std::to_string(k2) + ".bpp.txt");
                }

                // save alignment beams for the next iteration
                if (use_prev_outside_score) {
                    aln.ab.free();
                    if (itr < num_itr) {
                        aln.ab.save(aln);
                    }
                }
            }
            auto align_end_time = std::chrono::high_resolution_clock::now();

            if (verbose_state == VerboseState::DEBUG) {
                std::cerr
                    << "[ALIGNMENT] Total Time taken for iteration " << itr << ": "
                    << std::chrono::duration_cast<std::chrono::milliseconds>(align_end_time - align_start_time).count()
                    << "ms" << std::endl;
                std::cerr << "[ALIGNMENT] Total inside time for iteration " << itr << ": " << align_total_inside_time
                          << "ms" << std::endl;
                std::cerr << "[ALIGNMENT] Total outside time for iteration " << itr << ": " << align_total_outside_time
                          << "ms\n"
                          << std::endl;
            }
        }

        // fold step
        auto fold_start_time = std::chrono::high_resolution_clock::now();
        int fold_total_inside_time = 0;
        int fold_total_outside_time = 0;
        for (TurboPartition &pf : pfs) {
            pf.reset_beams(use_prev_outside_score ? false : true);

            auto fold_inside_start_time = std::chrono::high_resolution_clock::now();
            pf.compute_inside(beam_size);
            auto fold_inside_end_time = std::chrono::high_resolution_clock::now();

            auto fold_outside_start_time = std::chrono::high_resolution_clock::now();
            pf.compute_outside(use_lazy_outside ? folding_pruning_threshold : NEG_INF);
            auto fold_outside_end_time = std::chrono::high_resolution_clock::now();

            fold_total_inside_time +=
                std::chrono::duration_cast<std::chrono::milliseconds>(fold_inside_end_time - fold_inside_start_time)
                    .count();
            fold_total_outside_time +=
                std::chrono::duration_cast<std::chrono::milliseconds>(fold_outside_end_time - fold_outside_start_time)
                    .count();

            // // save partition function beams for the next iteration
            if (use_prev_outside_score) {
                pf.pfb.free();
                if (itr < num_itr) {
                    pf.pfb.save(pf);
                }
            }

            if (verbose_state == VerboseState::DEBUG) {
                pf.print_alpha_beta();
            }
        }
        for (TurboPartition &pf : pfs) {
            pf.compute_bpp_matrix();
            pf.calc_prob_accm();
            if (verbose_state == VerboseState::DETAIL) {
                pf.dump_bpp("./vb_info/" + std::to_string(itr) + "_pf_" + pf.sequence->id + ".bpp.txt");
            }

            if (itr == num_itr) {
                std::cout << ">" << pf.sequence->id << std::endl;
                std::cout << pf.get_threshknot_structure() << std::endl;
            }
        }
        auto fold_end_time = std::chrono::high_resolution_clock::now();

        if (VerboseState::DEBUG) {
            std::cerr << "\n[FOLDING] Total Time taken for iteration " << itr << ": "
                      << std::chrono::duration_cast<std::chrono::milliseconds>(fold_end_time - fold_start_time).count()
                      << "ms" << std::endl;
            std::cerr << "[FOLDING] Total inside time for iteration " << itr << ": " << fold_total_inside_time << "ms"
                      << std::endl;
            std::cerr << "[FOLDING] Total outside time for iteration " << itr << ": " << fold_total_outside_time
                      << "ms\n"
                      << std::endl;
        }

        reset_extinf_cache();
    }
}
