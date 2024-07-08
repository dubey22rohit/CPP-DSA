#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

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

  while (slow && fast) {
    if (slow->val != fast->val) {
      return false;
    }
    slow = slow->next;
    fast = fast->next;
  }
  return true;
}

int main() {
  ListNode* head = createList();
  cout << isPalindrome(head);
  return 0;
}