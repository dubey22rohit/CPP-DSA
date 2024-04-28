#include "ListNode.h"
#include <iostream>
using namespace std;

// LinkedList Cycle (easy)
//* https://leetcode.com/problems/linked-list-cycle/description/
bool hasCycle(ListNode *head) {
  ListNode *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
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
  cout << "LinkedList cycle start: " << hasCycle(head) << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: " << hasCycle(head) << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: " << hasCycle(head) << endl;

  head->next->next->next->next->next->next = new ListNode(10);
  cout << "LinkedList cycle start: " << hasCycle(head) << endl;

  return 0;
}
