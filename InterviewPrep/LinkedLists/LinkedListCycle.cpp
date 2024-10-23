#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

// https://leetcode.com/problems/linked-list-cycle/

bool hasCycle(ListNode* head) {
  ListNode *fast = head, *slow = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}

int main() { return 0; }