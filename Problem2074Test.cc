//
// Created by Efim Pyshnograev on 18/11/21.
//

#include "Problem2074.cc"
#include "memory"
#include "gtest/gtest.h"

namespace Problem2074 {
void compare(const std::initializer_list<int> &input_list,
             const std::initializer_list<int> &expected_list) {
  Solution solution;
  auto input{std::make_unique<ListNode, decltype(input_list)>(input_list)};
  auto expected{
      std::make_unique<ListNode, decltype(expected_list)>(expected_list)};
  auto actual{
      std::unique_ptr<ListNode>(solution.reverseEvenLengthGroups(input.get()))};
  ASSERT_EQ(*expected, *actual);
}

TEST(Problem2074, Trivial1) { compare({1, 2, 3}, {1, 3, 2}); }

TEST(Problem2074, Trivial2) { compare({0}, {0}); }

TEST(Problem2074, Sample1) {
  compare({5, 2, 6, 3, 9, 1, 7, 3, 8, 4}, {5, 6, 2, 3, 9, 1, 4, 8, 3, 7});
}

TEST(Problem2074, Sample2) { compare({1, 1, 0, 6}, {1, 0, 1, 6}); }

TEST(Problem2074, Sample3) { compare({1, 1, 0, 6, 5}, {1, 0, 1, 5, 6}); }

TEST(Problem2074, Sample4) { compare({1, 2}, {1, 2}); }
} // namespace Problem2074