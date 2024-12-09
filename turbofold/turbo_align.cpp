#include "turbofold.hpp"

double TurboAlign::beam_prune(std::unordered_map<std::pair<int, int>, HState, PairHash> &beamstep, HStateType h,
                              int beam_size) {
    std::vector<std::pair<double, std::pair<int, int>>> scores;
    scores.reserve(beamstep.size());

    for (auto it = beamstep.begin(); it != beamstep.end();) {
        std::pair<int, int> aij = it->first;
        HState &cand = it->second;

        double offset = 0;
        if (use_prev_outside_score && turbofold->itr > 1) {
            int s = aij.first + aij.second;
            std::unordered_map<std::pair<int, int>, HState, PairHash> *prev_beamstep;

            // Determine the correct previous beam step based on `h`
            switch (h) {
                case INS1:
                    prev_beamstep = &ab.bestINS1[s];
                    break;
                case INS2:
                    prev_beamstep = &ab.bestINS2[s];
                    break;
                case ALN:
                    prev_beamstep = &ab.bestALN[s];
                    break;
            }

            auto prev_it = prev_beamstep->find(aij);
            if (prev_it == prev_beamstep->end() || prev_it->second.beta <= LOG_OF_ZERO) {
                it = beamstep.erase(it);
                continue;
            }
            offset = prev_it->second.beta;
        }

        scores.push_back(std::make_pair(cand.alpha + offset, aij));
        ++it;  // Move to the next item
    }

    if (scores.size() <= beam_size) {
        return VALUE_MIN;
    }

    double threshold = Utility::quickselect(scores, 0, scores.size() - 1, scores.size() - beam_size);
    for (auto &p : scores) {
        if (p.first < threshold) beamstep.erase(p.second);
    }

    return threshold;
}
