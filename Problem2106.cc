#include <algorithm>
#include <any>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

namespace Problem2106 {
class Solution {
public:
  int maxTotalFruits(std::vector<std::vector<int>> &fruits, int startPos,
                     int k) {
    const int side_max = 200010;
    std::vector<int> applesOnLeft(side_max);
    std::vector<int> applesOnRight(side_max);

    int max_position = k;
    for (auto &pair : fruits) {
      int position = pair[0];
      int count = pair[1];

      if (position <= startPos) {
        applesOnLeft[startPos - position] = count;
        max_position = std::max(max_position, startPos - position);
      } else {
        applesOnRight[position - startPos] = count;
        max_position = std::max(max_position, position - startPos);
      }
    }

    for (int i = 1; i <= max_position; i++) {
      applesOnLeft[i] += applesOnLeft[i - 1];
      applesOnRight[i] += applesOnRight[i - 1];
    }

    // We know that we will get at least this number of apples (where we stand)
    int best = applesOnLeft[0];
    for (int first = 0; first <= k; ++first) {
      // Going `first` steps to the left and `max(0, k - 2 * first)` steps to
      // the right
      best = std::max(best, applesOnLeft[first] +
                                applesOnRight[std::max(0, k - 2 * first)]);
      // Going `first` steps to the right and `max(0, k - 2 * first)` steps to
      // the left
      best = std::max(best, applesOnRight[first] +
                                applesOnLeft[std::max(0, k - 2 * first)]);
    }

    return best;
  }
};
} // namespace Problem2106