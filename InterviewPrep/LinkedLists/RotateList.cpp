#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
  if (!head || !head->next || k == 0) {
    return head;
  }

  int len = 1;
  ListNode* p = head;
  while (p->next) {
    len++;
    p = p->next;
  }
  if (k % len == 0) {
    return head;
  }
  k = len - (k % len);

  p->next = head;
  while (k--) {
    p = p->next;
  }

  ListNode* newHead = p->next;
  p->next = nullptr;

  return newHead;
}

int main() {
  ListNode* head = createList();
  ListNode* rotatedList = rotateRight(head, 2);
  printList(rotatedList);
  return 0;
}