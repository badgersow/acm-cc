#include "vector"
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>

namespace Problem2104_linear {

struct Positioned {
  const int index;
  const int value;
};

class Solution {
private:
  template <typename Comparison>
  std::vector<int> index_of_left_comp(const std::vector<int> &original,
                                      Comparison compare) {
    std::vector<Positioned> stack;
    std::vector<int> result;
    for (int i = 0; i < original.size(); ++i) {
      int element = original[i];
      // First, we just pop from the stack while head is < x
      while (!stack.empty() && compare(stack.back().value, element)) {
        stack.pop_back();
      }
      // Then, we save the position
      result.push_back(stack.empty() ? -1 : stack.back().index);
      // And finally, add the current element to the stack
      stack.push_back({.index = i, .value = element});
    }
    return result;
  }

public:
  std::vector<int> reverse_vector(const std::vector<int> &original) {
    std::vector<int> reversed(original);
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
  }
  std::vector<int> invert_indexes(const std::vector<int> &original) {
    std::vector<int> result;
    std::transform(original.begin(), original.end(), std::back_inserter(result),
                   [&original](int x) { return original.size() - 1 - x; });
    return result;
  }
  std::vector<int> index_of_left_ge(const std::vector<int> &original) {
    return index_of_left_comp(original, [](int a, int b) { return a < b; });
  }
  std::vector<int> index_of_right_g(const std::vector<int> &original) {
    return reverse_vector(invert_indexes(index_of_left_comp(
        reverse_vector(original), [](int a, int b) { return a <= b; })));
  }
  std::vector<int> index_of_left_le(const std::vector<int> &original) {
    return index_of_left_comp(original, [](int a, int b) { return a > b; });
  }
  std::vector<int> index_of_right_l(const std::vector<int> &original) {
    return reverse_vector(invert_indexes(index_of_left_comp(
        reverse_vector(original), [](int a, int b) { return a >= b; })));
  }
  long long subArrayRanges(std::vector<int> &a) {
    std::vector<int> left_ge = index_of_left_ge(a);
    std::vector<int> right_g = index_of_right_g(a);
    std::vector<int> left_le = index_of_left_le(a);
    std::vector<int> right_l = index_of_right_l(a);
    long long result = 0LL;
    for (int i = 0; i < a.size(); ++i) {
      result += static_cast<long long>(a[i]) * (i - left_ge[i]) *
                (right_g[i] - i);
      result -= static_cast<long long>(a[i]) * (i - left_le[i]) *
                (right_l[i] - i);
    }
    return result;
  }
};
} // namespace Problem2104_linear