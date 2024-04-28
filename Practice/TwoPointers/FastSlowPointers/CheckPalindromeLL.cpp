#include "ListNode.h"
#include <iostream>
using namespace std;

// Palindrome LinkedList (medium)
ListNode *reverseLL(ListNode *head) {
  ListNode *p = head, *q = nullptr, *r = nullptr;
  while (p) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  return q;
}

bool isPalindrome(ListNode *head) {
  ListNode *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  slow = reverseLL(slow);
  // We can create a new ListNode* to the start of the LL but this is fine, why
  // allocate extra space? :D
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

int main(int argc, char *argv[]) {
  ListNode *head = createList();
  cout << (isPalindrome(head) ? "yes" : "no");

  return 0;
}
