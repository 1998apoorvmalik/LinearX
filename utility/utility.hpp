#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>
#include "./constants.hpp"

// used for hashing a pair of integers
struct PairHash {
    std::size_t operator()(const std::pair<int, int> &p) const {
        std::size_t i = static_cast<std::size_t>(p.first);
        std::size_t j = static_cast<std::size_t>(p.second);

        // combine i and j using bit manipulation
        std::size_t hash = i ^ ((j << 16) | (j >> 16));

        // apply an additional mix to further reduce collisions
        hash ^= (hash >> 13);
        hash *= GOLDEN_RATIO; // a large prime number
        hash ^= (hash >> 15);

        return hash;
    }
};

inline bool check_valid_pair(const int nuc1, const int nuc2) { return (nuc1 + nuc2) > 3 && (nuc1 + nuc2) % 2 != 0; }

inline int quickselect_partition(std::vector<std::pair<double , int>> &scores, int lower, int upper) {
    double  pivot = scores[upper].first;
    while (lower < upper) {
        while (scores[lower].first < pivot)
            ++lower;
        while (scores[upper].first > pivot)
            --upper;
        if (scores[lower].first == scores[upper].first)
            ++lower;
        else if (lower < upper)
            swap(scores[lower], scores[upper]);
    }
    return upper;
}

// in-place quick-select
inline double quickselect(std::vector<std::pair<double , int>> &scores, int lower, int upper, int k) {
    if (lower == upper)
        return scores[lower].first;
    int split = quickselect_partition(scores, lower, upper);
    int length = split - lower + 1;
    if (length == k)
        return scores[split].first;
    else if (k < length)
        return quickselect(scores, lower, split - 1, k);
    else
        return quickselect(scores, split + 1, upper, k - length);
}

#endif // UTILITIES_HPP
