//
// Created by Efim Pyshnograev on 18/11/21.
//

#include "vector"

class Solution {
public:
  int timeRequiredToBuy(const std::vector<int> &tickets, int k) {
    int result = 0;
    for (int i = 0; i <= k; i++) {
      result += std::min(tickets[k], tickets[i]);
    }
    for (int i = k + 1; i < tickets.size(); i++) {
      result += std::min(tickets[k] - 1, tickets[i]);
    }
    return result;
  }
};