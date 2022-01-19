#include "Problem2136.cc"
#include "gtest/gtest.h"
#include <vector>

namespace Problem2136 {
namespace {
class Problem2136 : public testing::Test {
protected:
  Solution solution{};
};

TEST_F(Problem2136, Sample1) {
  std::vector plant_time{1, 4, 3};
  std::vector grow_time{2, 3, 1};

  int result = solution.earliestFullBloom(plant_time, grow_time);
  EXPECT_EQ(result, 9);
}

TEST_F(Problem2136, Sample2) {
  std::vector plant_time{1, 2, 3, 2};
  std::vector grow_time{2, 1, 2, 1};

  int result = solution.earliestFullBloom(plant_time, grow_time);
  EXPECT_EQ(result, 9);
}

TEST_F(Problem2136, Sample3) {
  std::vector plant_time{1};
  std::vector grow_time{1};

  int result = solution.earliestFullBloom(plant_time, grow_time);
  EXPECT_EQ(result, 2);
}

} // namespace
} // namespace Problem2136