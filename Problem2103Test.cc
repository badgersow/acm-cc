#include "Problem2103.cc"
#include "gtest/gtest.h"

namespace Problem2103 {
TEST(Problem2103, Sample1) {
  Solution s;
  const int result = s.countPoints("B0B6G0R6R0R6G9");
  EXPECT_EQ(result, 1);
}

TEST(Problem2103, Sample2) {
  Solution s;
  const int result = s.countPoints("B0R0G0R9R0B0G0");
  EXPECT_EQ(result, 1);
}

TEST(Problem2103, Sample3) {
  Solution s;
  const int result = s.countPoints("G4");
  EXPECT_EQ(result, 0);
}
} // namespace Problem2103