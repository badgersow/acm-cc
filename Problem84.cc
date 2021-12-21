//
// Created by Efim Pyshnograev on 1/12/21.
//

#include "vector"

namespace Problem84 {
class Solution {
public:
  int largestRectangleArea(std::vector<int> &hist) {
    hist.emplace_back(0);
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
};
} // namespace Problem84