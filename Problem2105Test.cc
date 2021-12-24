#include "Problem2105.cc"
#include "gtest/gtest.h"
#include <vector>

namespace Problem2105 {

TEST(Problem2105, Sample1) {
  std::vector<int> input{2, 2, 3, 3};
  int capacityA = 5;
  int capacityB = 5;
  int expected = 1;
  EXPECT_EQ(expected, Solution().minimumRefill(input, capacityA, capacityB));
}

TEST(Problem2105, Sample2) {
  std::vector<int> input{2, 2, 3, 3};
  int capacityA = 3;
  int capacityB = 4;
  int expected = 2;
  EXPECT_EQ(expected, Solution().minimumRefill(input, capacityA, capacityB));
}

TEST(Problem2105, Sample3) {
  std::vector<int> input{5};
  int capacityA = 10;
  int capacityB = 8;
  int expected = 0;
  EXPECT_EQ(expected, Solution().minimumRefill(input, capacityA, capacityB));
}

TEST(Problem2105, Trivial1) {
  std::vector<int> input{2};
  int capacityA = 1;
  int capacityB = 1;
  int expected = 1;
  EXPECT_EQ(expected, Solution().minimumRefill(input, capacityA, capacityB));
}

} // namespace Problem2105