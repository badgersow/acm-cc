#include <vector>

namespace Problem2105 {
class Solution {
public:
  int minimumRefill(std::vector<int> &a, int capacityA, int capacityB) {
    // First, let's compute Alice
    int refills = 0;
    int alice_tank = capacityA;
    for (int i = 0; i < a.size() / 2; ++i) {
      if (alice_tank < a[i]) {
        alice_tank = capacityA;
        refills++;
      }
      alice_tank -= a[i];
    }
    // Now, calculating Bob
    int bob_tank = capacityB;
    for (int i = 0; i < a.size() / 2; ++i) {
      if (bob_tank < a[a.size() - 1 - i]) {
        bob_tank = capacityB;
        refills++;
      }
      bob_tank -= a[a.size() - 1 - i];
    }
    // And lastly, middle plant
    if (a.size() % 2 == 1 && a[a.size() / 2] > alice_tank &&
        a[a.size() / 2] > bob_tank) {
      refills++;
    }
    return refills;
  }
};
} // namespace Problem2105