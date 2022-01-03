#include "Problem1383.cc"
#include "gtest/gtest.h"
#include <vector>

namespace Problem1383 {
namespace {
TEST(Problem1383, Sample1) {
  std::vector<int> speed{2, 10, 3, 1, 5, 8};
  std::vector<int> efficiency{5, 4, 3, 9, 7, 2};
  int k = 2;
  int expected = 60;

  EXPECT_EQ(expected,
            Solution().maxPerformance(speed.size(), speed, efficiency, k));
}
} // namespace
} // namespace Problem1383