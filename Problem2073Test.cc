//
// Created by Efim Pyshnograev on 18/11/21.
//

#include "gtest/gtest.h"
#include "Problem2073.cc"

TEST(Problem2073, Sample1) {
  Solution solution;
  ASSERT_EQ(
      6,
      solution.timeRequiredToBuy(
          std::vector<int>{2, 3, 2},
          2));
}

TEST(Problem2073, Sample2) {
  Solution solution;
  ASSERT_EQ(
      8,
      solution.timeRequiredToBuy(
          std::vector<int>{5, 1, 1, 1},
          0));
}
