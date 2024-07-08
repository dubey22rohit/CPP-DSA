#include <iostream>

#include "../Helpers/ListNode.h"

using namespace std;

static bool hasCycle(ListNode *head) {
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

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList has cycle: " << hasCycle(head) << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList has cycle: " << hasCycle(head) << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList has cycle: " << hasCycle(head) << endl;

  head->next->next->next->next->next->next = new ListNode(10);
  cout << "LinkedList has cycle: " << hasCycle(head) << endl;
  return 0;
}