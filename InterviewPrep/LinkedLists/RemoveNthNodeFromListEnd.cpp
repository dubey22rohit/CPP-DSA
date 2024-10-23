#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (head->next == nullptr) {
    return nullptr;
  }

  ListNode *fast = head, *slow = head;

  while (n--) {
    fast = fast->next;
  }
  if (!fast) {
    return head->next;
  }
  while (fast->next) {
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = slow->next->next;
  return head;
}

int main() { return 0; }