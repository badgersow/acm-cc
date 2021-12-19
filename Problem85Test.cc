//
// Created by Efim Pyshnograev on 1/12/21.
//

#include "Problem85.cc"
#include "vector"
#include "gtest/gtest.h"

TEST(Problem85, Trivial) {
  std::vector<std::vector<char>> input{{'1'}};
  Solution solution;
  int result = solution.maximalRectangle(input);
  EXPECT_EQ(result, 1);
}

TEST(Problem85, Sample1) {
  std::vector<std::vector<char>> input{{'1', '0', '1', '0', '0'},
                                       {'1', '0', '1', '1', '1'},
                                       {'1', '1', '1', '1', '1'},
                                       {'1', '0', '0', '1', '0'}};
  Solution solution;
  int result = solution.maximalRectangle(input);
  EXPECT_EQ(result, 6);
}

TEST(Problem85, Sample2) {
  std::vector<std::vector<char>> input{{}};
  Solution solution;
  int result = solution.maximalRectangle(input);
  EXPECT_EQ(result, 0);
}

TEST(Problem85, Sample3) {
  std::vector<std::vector<char>> input{{'0'}};
  Solution solution;
  int result = solution.maximalRectangle(input);
  EXPECT_EQ(result, 0);
}

TEST(Problem85, Sample4) {
  std::vector<std::vector<char>> input{{'1'}};
  Solution solution;
  int result = solution.maximalRectangle(input);
  EXPECT_EQ(result, 1);
}

TEST(Problem85, Sample5) {
  std::vector<std::vector<char>> input{{'0', '0'}};
  Solution solution;
  int result = solution.maximalRectangle(input);
  EXPECT_EQ(result, 0);
}

TEST(Problem85, Custom1) {
  std::vector<std::vector<char>> input{{'1', '1'}};
  Solution solution;
  int result = solution.maximalRectangle(input);
  EXPECT_EQ(result, 2);
}

TEST(Problem85, Custom2) {
  std::vector<std::vector<char>> input{{'1', '1'}, {'1', '1'}};
  Solution solution;
  int result = solution.maximalRectangle(input);
  EXPECT_EQ(result, 4);
}

TEST(Problem85, Custom3) {
  std::vector<std::vector<char>> input{
      {'1', '1', '0'}, {'1', '1', '0'}, {'1', '0', '0'}};
  Solution solution;
  int result = solution.maximalRectangle(input);
  EXPECT_EQ(result, 4);
}

TEST(Problem85, HistogramCustom1) {
  std::vector<int> hist{2, 1, 1, 0};
  Solution solution;
  int actual = solution.maxInHistogram(hist);
  EXPECT_EQ(actual, 3);
}