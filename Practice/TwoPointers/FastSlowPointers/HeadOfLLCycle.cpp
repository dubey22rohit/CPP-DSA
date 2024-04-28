#include "ListNode.h"
#include <iostream>
using namespace std;

// Start of LinkedList Cycle (medium)
ListNode *findCycleStart(ListNode *head) {
  ListNode *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) {
      break;
    }
  }
  // if loop does not exist
  if (slow != fast) {
    return nullptr;
  }
  // if loop does exist
  // Start slow from head and fast from meeting point
  slow = head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle start: " << findCycleStart(head)->val << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: " << findCycleStart(head)->val << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: " << findCycleStart(head)->val << endl;

  return 0;
}
