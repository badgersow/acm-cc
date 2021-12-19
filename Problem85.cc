//
// Created by Efim Pyshnograev on 1/12/21.
//

#include "vector"

class Solution {
public:
  // Precondition: hist's last element should be 0
  int maxInHistogram(const std::vector<int> &hist) {
    assert(hist[hist.size() - 1] == 0);
    std::vector<std::pair<int, int>> stack;
    int best = 0;
    for (int i = 0; i < hist.size(); ++i) {
      int earliest_with_at_least = i;
      while (!stack.empty() && stack.back().first > hist[i]) {
        auto [prev_value, prev_position] = stack.back();
        stack.pop_back();
        best = std::max(best, prev_value * (i - prev_position));
        earliest_with_at_least = prev_position;
      }
      stack.emplace_back(std::make_pair(hist[i], earliest_with_at_least));
    }
    return best;
  }

  int maximalRectangle(std::vector<std::vector<char>> &matrix) {
    if (matrix.empty()) {
      return 0;
    }
    std::vector<int> histogram(matrix[0].size() + 1, 0);
    int best = 0;
    for (const auto &row : matrix) {
      for (int i = 0; i < row.size(); ++i) {
        if (row[i] == '1') {
          histogram[i]++;
        } else {
          histogram[i] = 0;
        }
      }
      best = std::max(best, maxInHistogram(histogram));
    }
    return best;
  }
};