//
// Created by Efim Pyshnograev on 18/11/21.
//

#include "vector"
#include <initializer_list>

struct ListNode {
  int val{};
  ListNode *next{nullptr};

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  ListNode(const std::initializer_list<int> &list)
      : ListNode(list.begin(), list.end()) {}

  ListNode(const std::initializer_list<int>::iterator begin,
           const std::initializer_list<int>::iterator end)
      : val(*begin) {
    if (begin + 1 != end) {
      next = new ListNode(begin + 1, end);
    }
  }

  // Rule of 5
  ListNode(ListNode &) = delete;
  ListNode(ListNode &&) = delete;

  ListNode &operator=(ListNode &) = delete;
  ListNode &operator=(ListNode &&) = delete;

  bool operator==(const ListNode &rhs) const {
    if (val != rhs.val) {
      return false;
    }
    if (!next && !rhs.next) {
      return true;
    }
    if (!next || !rhs.next) {
      return false;
    }
    return (*next) == (*rhs.next);
  }

  ~ListNode() { delete next; }
};

class Solution {
public:
  ListNode *append(ListNode *node, int value) {
    if (node->val == -1) {
      // This is head. Just fill it.
      node->val = value;
      return node;
    }

    ListNode *next = new ListNode(value);
    node->next = next;
    return next;
  }

  ListNode *reverseEvenLengthGroups(ListNode *const head) {
    std::vector<int> elements;
    std::vector<int> stack;
    ListNode *current = head;
    while (current) {
      elements.push_back(current->val);
      current = current->next;
    }

    int group_size = 1;
    bool reversed = false;
    int i = 0;

    ListNode *new_head = new ListNode(-1);
    ListNode *new_current = new_head;
    while (i < elements.size()) {
      for (int j = 0; j < group_size && i + j < elements.size(); j++) {
        stack.push_back(elements[i + j]);
      }

      for (int j = 0; j < stack.size(); j++) {
        if (stack.size() % 2 == 1) {
          // If even, then don't reverse
          new_current = append(new_current, stack[j]);
        } else {
          new_current = append(new_current, stack[stack.size() - j - 1]);
        }
      }

      stack.clear();
      i += group_size;
      group_size++;
    }

    return new_head;
  }
};