#include <iostream>

#include "Helpers/ListNode.h"
using namespace std;

// https://leetcode.com/problems/palindrome-linked-list/

ListNode* reverseLL(ListNode* head) {
  ListNode *p = head, *q = nullptr, *r = nullptr;
  while (p) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  return q;
}

bool isPalindrome(ListNode* head) {
  ListNode *fast = head, *slow = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }

  slow = reverseLL(slow);
  fast = head;
  while (fast && slow) {
    if (fast->val != slow->val) {
      return false;
    }
    slow = slow->next;
    fast = fast->next;
  }
  return true;
}

int main() { return 0; }