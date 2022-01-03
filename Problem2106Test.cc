#include "Problem2106.cc"
#include "gtest/gtest.h"
#include <vector>

namespace Problem2106 {
namespace {
TEST(Problem2106, Sample1) {
  std::vector<std::vector<int>> apples = {{2, 8}, {6, 3}, {8, 6}};
  const int startPos = 5;
  const int k = 4;
  const int expected = 9;

  EXPECT_EQ(expected, Solution().maxTotalFruits(apples, startPos, k));
}

TEST(Problem2106, Sample2) {
  std::vector<std::vector<int>> apples = {{0, 9}, {4, 1}, {5, 7},
                                          {6, 2}, {7, 4}, {10, 9}};
  const int startPos = 5;
  const int k = 4;
  const int expected = 14;

  EXPECT_EQ(expected, Solution().maxTotalFruits(apples, startPos, k));
}

TEST(Problem2106, Sample3) {
  std::vector<std::vector<int>> apples = {{0, 3}, {6, 4}, {8, 5}};
  const int startPos = 3;
  const int k = 2;
  const int expected = 0;

  EXPECT_EQ(expected, Solution().maxTotalFruits(apples, startPos, k));
}
} // namespace
} // namespace Problem2106