#include "Problem2104_linear.cc"
#include "vector"
#include "gtest/gtest.h"

namespace Problem2104_linear {
TEST(Problem2104_linear, Sample1) {
  std::vector<int> input{1, 2, 3};
  EXPECT_EQ(4, Solution().subArrayRanges(input));
}

TEST(Problem2104_linear, Sample2) {
  std::vector<int> input{1, 3, 3};
  EXPECT_EQ(4, Solution().subArrayRanges(input));
}

TEST(Problem2104_linear, Sample3) {
  std::vector<int> input{4, -2, -3, 4, 1};
  EXPECT_EQ(59, Solution().subArrayRanges(input));
}

TEST(Problem2104_linear, Trivial1) {
  std::vector<int> input{1};
  EXPECT_EQ(0, Solution().subArrayRanges(input));
}

TEST(Problem2104_linear, Trivial2) {
  std::vector<int> input{1, 2};
  EXPECT_EQ(1, Solution().subArrayRanges(input));
}

TEST(Problem2104_linear, FindLeftGe1) {
  std::vector<int> input{4, 2, 1, 4, 3};
  std::vector<int> expected{-1, 0, 1, 0, 3};
  EXPECT_EQ(expected, Solution().index_of_left_ge(input));
}

TEST(Problem2104_linear, FindRightG1) {
  std::vector<int> input{4, 2, 1, 4, 3};
  std::vector<int> expected{5, 3, 3, 5, 5};
  EXPECT_EQ(expected, Solution().index_of_right_g(input));
}

TEST(Problem2104_linear, FindRightG2) {
  std::vector<int> input{7, 3, 1, 3, 1};
  std::vector<int> expected{5, 5, 3, 5, 5};
  EXPECT_EQ(expected, Solution().index_of_right_g(input));
}

TEST(Problem2104_linear, InvertIndexes1) {
  std::vector<int> input{-1, 0, 1, 0, 3};
  std::vector<int> expected{5, 4, 3, 4, 1};
  EXPECT_EQ(expected, Solution().invert_indexes(input));
}

TEST(Problem2104_linear, Reverse1) {
  std::vector<int> input{4, 2, 1, 4, 3};
  std::vector<int> expected{3, 4, 1, 2, 4};
  EXPECT_EQ(expected, Solution().reverse_vector(input));
}

} // namespace Problem2104_linear