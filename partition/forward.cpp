#include "./partition.hpp"

double Partition::beam_prune(std::unordered_map<int, State> &beamstep) {
    if (beam_size == 0 || beamstep.size() <= beam_size) {
        return VALUE_MIN;
    }
    std::vector<std::pair<double, int>> scores;
    scores.clear();
    for (auto &item : beamstep) {
        int i = item.first;
        State &cand = item.second;
        int k = i - 1;
        double newalpha = (k >= 0 ? bestC[k].alpha : double(0.0)) + cand.alpha;
        scores.push_back(std::make_pair(newalpha, i));
    }
    if (scores.size() <= beam_size) {
        return VALUE_MIN;
    }
    double threshold = quickselect(scores, 0, scores.size() - 1, scores.size() - beam_size);
    for (auto &p : scores) {
        if (p.first < threshold)
            beamstep.erase(p.second);
    }
    return threshold;
}

void Partition::update_score(State &state, const int new_score, const double prev_score = 0) {
    num_alpha_updates += 1;
    if (mode == MFE) {
        state.alpha = std::max(state.alpha, prev_score + new_score);
    } else {
        Fast_LogPlusEquals(state.alpha, prev_score + new_score * INV_KT);
    }
}

void Partition::beamstep_H(const int j, const std::vector<int> *next_pair) {
    int jnext = next_pair[seq[j]][j];
    while (!allow_sharp_turn && jnext < seq.size() && (jnext - j) < 4) {
        jnext = next_pair[seq[j]][jnext];
    }

    if (jnext < seq.size()) {
        int score = -energy_model->score_hairpin(j, jnext, seq[j], seq[j + 1], seq[jnext - 1], seq[jnext], -1);
        update_score(bestH[jnext][j], score);
    }

    // for every state h in H[j]
    //   1. extend H(i, j) to H(i, jnext)
    //   2. generate P(i, j)
    // std::cout << "Size: " << bestH[j].size() << std::endl;
    for (auto &item : bestH[j]) {
        int i = item.first;
        State &state = item.second;

        // 1. extend H(i, j) to H(i, jnext)
        int jnext = next_pair[seq[i]][j];
        if (jnext < seq.size()) {
            int score = -energy_model->score_hairpin(i, jnext, seq[i], seq[i + 1], seq[jnext - 1], seq[jnext], -1);
            update_score(bestH[jnext][i], score);
        }

        // 2. generate P(i, j)
        update_score(bestP[j][i], 0, state.alpha);
    }
}

void Partition::beamstep_Multi(const int j, const std::vector<int> *next_pair) {
    for (auto &item : bestMulti[j]) {
        int i = item.first;
        State &state = item.second;

        // 1. extend Multi(i, j) to Multi(i, jnext)
        int jnext = next_pair[seq[i]][j];
        if (jnext < seq.size()) {
            int new_score = -energy_model->score_multi_unpaired(j, jnext);
            update_score(bestMulti[jnext][i], new_score, state.alpha);
        }

        // 2. generate P(i, j)
        int new_score = -energy_model->score_multi(i, j, seq[i], seq[i + 1], seq[j - 1], seq[j], seq.size());
        update_score(bestP[j][i], new_score, state.alpha);
    }
}

void Partition::beamstep_P(const int j, const std::vector<int> *next_pair) {
    // for every state in P[j]
    //   1. generate new P (helix/bulge)
    //   2. M = P
    //   3. M2 = M + P
    //   4. C = C + P

    for (auto &item : bestP[j]) {
        int i = item.first;
        State &state = item.second;

        // 1. generate new P (helix/bulge)
        for (int p = i - 1; p >= std::max(0, i - MAXLOOPSIZE); --p) {
            int q = next_pair[seq[p]][j];
            while (q < seq.size() && ((i - p) + (q - j) - 2) <= MAXLOOPSIZE) {
                // current shape is: p...i (pair) j...q
                int new_score = -energy_model->score_single_loop(p, q, i, j, seq[p], seq[p + 1], seq[q - 1], seq[q],
                                                                 seq[i - 1], seq[i], seq[j], seq[j + 1]);
                update_score(bestP[q][p], new_score, state.alpha);
                q = next_pair[seq[p]][q];
            }
        }

        // 2. M = P
        if (i > 0 && j < seq.size() - 1) {
            int new_score = -energy_model->score_M1(i, j, j, seq[i - 1], seq[i], seq[j],
                                                    (j + 1 < seq.size() ? seq[j + 1] : -1), seq.size());
            update_score(bestM[j][i], new_score, state.alpha);
        }

        // 3. M2 = M + P
        int h = i - 1;
        if (h > 0 && !bestM[h].empty()) {
            int new_score = -energy_model->score_M1(i, j, j, seq[i - 1], seq[i], seq[j],
                                                    (j + 1 < seq.size() ? seq[j + 1] : -1), seq.size());
            for (auto &m_item : bestM[h]) {
                int g = m_item.first;
                State &m_state = m_item.second;
                update_score(bestM2[j][g], new_score, m_state.alpha + state.alpha);
            }
        }

        // 4. C = C + P
        h = i - 1;
        if (h >= 0) {
            State &prefix_C = bestC[h];
            int new_score = -energy_model->score_external_paired(i, j, seq[h], seq[h + 1], seq[j],
                                                                 (j + 1 < seq.size() ? seq[j + 1] : -1), seq.size());
            update_score(bestC[j], new_score, prefix_C.alpha + state.alpha);
        } else {
            int new_score = -energy_model->score_external_paired(0, j, -1, seq[0], seq[j],
                                                                 (j + 1 < seq.size() ? seq[j + 1] : -1), seq.size());
            update_score(bestC[j], new_score, state.alpha);
        }
    }
}

void Partition::beamstep_M2(const int j, const std::vector<int> *next_pair) {
    for (auto &item : bestM2[j]) {
        int i = item.first;
        State &state = item.second;

        // 1. multi-loop = M2
        for (int p = i - 1; p >= std::max(0, i - MAXLOOPSIZE); --p) {
            int q = next_pair[seq[p]][j];
            if (q < seq.size()) {
                int new_score =
                    -(energy_model->score_multi_unpaired(p, i - 1) + energy_model->score_multi_unpaired(j, q - 1));
                update_score(bestMulti[q][p], new_score, state.alpha);
            }
        }

        // 2. M = M2
        update_score(bestM[j][i], 0, state.alpha);
    }
}

void Partition::beamstep_M(const int j) {
    for (auto &item : bestM[j]) {
        int i = item.first;
        State &state = item.second;

        if (j < seq.size() - 1) {
            int new_score = -energy_model->score_multi_unpaired(j, j + 1);
            update_score(bestM[j + 1][i], new_score, state.alpha);
        }
    }
}

void Partition::beamstep_C(const int j) {
    if (j < seq.size() - 1) {
        update_score(bestC[j + 1], 0, bestC[j].alpha);
    }
}