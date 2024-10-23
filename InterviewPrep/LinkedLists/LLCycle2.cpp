#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

// https://leetcode.com/problems/linked-list-cycle-ii
// Find the node where the cycle starts
ListNode* detectCycle(ListNode* head) {
  ListNode *fast = head, *slow = head;

  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) {
      slow = head;
      while (slow && fast) {
        if (slow == fast) {
          return slow;
        }
        slow = slow->next;
        fast = fast->next;
      }
    }
  }
  return NULL;
}

int main() { return 0; }