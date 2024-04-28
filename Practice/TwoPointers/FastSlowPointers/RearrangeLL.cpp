#include "ListNode.h"
#include <iostream>
using namespace std;

// Rearrange a LinkedList (medium)
ListNode *reverse(ListNode *head) {
  ListNode *p = head, *q = nullptr, *r = nullptr;
  while (p) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  return q;
}

void reorder(ListNode *head) {
  ListNode *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *firstHalf = head, *revSecondHalf = reverse(slow);

  while (firstHalf && revSecondHalf) {
    ListNode *temp = firstHalf->next;
    firstHalf->next = revSecondHalf;
    firstHalf = temp;

    temp = revSecondHalf->next;
    revSecondHalf->next = firstHalf;
    revSecondHalf = temp;
  }

  if (firstHalf) {
    firstHalf->next = nullptr;
  }
}

int main(int argc, char *argv[]) {
  ListNode *head = createList();
  printList(head);
  reorder(head);
  printList(head);

  return 0;
}
