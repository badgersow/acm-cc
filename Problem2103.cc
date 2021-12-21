#include "string"
#include "vector"
#include <cstdlib>
#include <stdexcept>

namespace Problem2103 {
class Solution {
  int color_mask(char color) {
    switch (color) {
    case 'R':
      return 1 << 0;
    case 'G':
      return 1 << 1;
    case 'B':
      return 1 << 2;
    default:
      throw std::runtime_error("Unknown color has been passed");
    }
  }

  const int all_color_mask = (1 << 0) + (1 << 1) + (1 << 2);

public:
  int countPoints(std::string rings) {
    std::vector<int> mask(10, 0);
    for (int i = 0; i < rings.size(); i += 2) {
      char color = rings[i];
      int rod = rings[i + 1] - '0';

      mask[rod] |= color_mask(color);
    }
    int result = 0;
    for (auto element : mask) {
      if (element == all_color_mask) {
        result++;
      }
    }
    return result;
  }
};
} // namespace Problem2103