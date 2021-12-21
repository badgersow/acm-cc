#include "vector"
#include <algorithm>
#include <iostream>
#include <ostream>

namespace Problem2104_quadratic {
class Solution {
public:
  long long subArrayRanges(std::vector<int> &a) {
    const int n = a.size();

    long long result = 0LL;
    for (int i = 0; i < n; ++i) {
      int rolling_max = a[i];
      int rolling_min = a[i];
      for (int j = i; j < n; ++j) {
        rolling_max = std::max(rolling_max, a[j]);
        rolling_min = std::min(rolling_min, a[j]);
        result += (rolling_max - rolling_min);
      }
    }
    return result;
  }
};
} // namespace Problem2104_quadratic