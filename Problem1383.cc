#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

namespace Problem1383 {
class Solution {
public:
  int maxPerformance(int n, std::vector<int> &speed,
                     std::vector<int> &efficiency, int k) {
    std::unordered_map<int, std::vector<int>> speeds_by_efficiency;
    std::set<int> efficiencies;
    for (int i = 0; i < speed.size(); ++i) {
      efficiencies.insert(efficiency[i]);
      speeds_by_efficiency[efficiency[i]].push_back(speed[i]);
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        hired; // HIRED
    std::int64_t speed_sum = 0;
    std::int64_t best_result = 0;
    const std::int64_t P = 1000000007;
    for (auto eff = efficiencies.rbegin(); eff != efficiencies.rend(); ++eff) {
      int current_efficiency = *eff;
      // Hire all the developers, if that makes any sense.
      for (int speed : speeds_by_efficiency[current_efficiency]) {
        if (hired.size() < k) {
          // If we don't have the full team
          hired.push(speed);
          speed_sum += speed;
        } else if (hired.top() < speed) {
          // If the current slowest guy is worse, we need to replace it
          speed_sum -= hired.top();
          hired.pop();
          hired.push(speed);
          speed_sum += speed;
        }
        best_result = std::max(best_result, current_efficiency * speed_sum);
      }
    }
    return best_result % P;
  }
};
} // namespace Problem1383