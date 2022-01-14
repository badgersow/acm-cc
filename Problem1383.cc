#include <queue>
#include <vector>

namespace Problem1383 {
class Solution {
public:
  int maxPerformance(int n, std::vector<int> &speed,
                     std::vector<int> &efficiency, int k) {
    std::vector<std::pair<int, int>> e_speed;
    for (int i = 0; i < speed.size(); ++i) {
      e_speed.push_back(std::make_pair(efficiency[i], speed[i]));
    }
    std::sort(e_speed.begin(), e_speed.end(),
              [](std::pair<int, int> first, std::pair<int, int> second) {
                return first.first >
                       second.first; // larger efficiency comes first
              });
    std::priority_queue<int, std::vector<int>, std::greater<int>> hired;
    std::int64_t speed_sum = 0;
    std::int64_t best_result = 0;
    const std::int64_t P = 1000000007;
    for (std::pair<int, int> pair : e_speed) {
      int current_efficiency = pair.first;
      int speed = pair.second;
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
    return best_result % P;
  }
};
} // namespace Problem1383