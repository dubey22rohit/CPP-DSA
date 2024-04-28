#include "ListNode.h"
#include <iostream>
using namespace std;

// Middle of the LinkedList (easy)
ListNode *findMiddle(ListNode *head) {
  ListNode *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << "Middle Node: " << findMiddle(head)->val << endl;

  head->next->next->next->next->next = new ListNode(6);
  cout << "Middle Node: " << findMiddle(head)->val << endl;

  head->next->next->next->next->next->next = new ListNode(7);
  cout << "Middle Node: " << findMiddle(head)->val << endl;
}
