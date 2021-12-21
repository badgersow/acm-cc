#include "Problem2104_quadratic.cc"
#include "vector"
#include "gtest/gtest.h"

namespace Problem2104_quadratic {
TEST(Problem2104_quadratic, Sample1) {
  std::vector<int> input{1, 2, 3};
  EXPECT_EQ(4, Solution().subArrayRanges(input));
}

TEST(Problem2104_quadratic, Sample2) {
  std::vector<int> input{1, 3, 3};
  EXPECT_EQ(4, Solution().subArrayRanges(input));
}

TEST(Problem2104_quadratic, Sample3) {
  std::vector<int> input{4, -2, -3, 4, 1};
  EXPECT_EQ(59, Solution().subArrayRanges(input));
}

TEST(Problem2104_quadratic, Trivial1) {
  std::vector<int> input{1};
  EXPECT_EQ(0, Solution().subArrayRanges(input));
}
} // namespace Problem2104_quadratic