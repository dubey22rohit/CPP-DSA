#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

ListNode* findMiddle(ListNode* head) {
  ListNode *fast = head, *slow = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

/*
Time complexity #
The above algorithm will have a time complexity of
O(N) where ‘N’ is the number of nodes in the LinkedList.

Space complexity #
The algorithm runs in constant space O(1).
*/

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << "LinkedList middle: " << findMiddle(head)->val << endl;

  head->next->next->next->next->next = new ListNode(6);
  cout << "LinkedList middle: " << findMiddle(head)->val << endl;

  head->next->next->next->next->next->next = new ListNode(7);
  cout << "LinkedList middle: " << findMiddle(head)->val << endl;

  return 0;
}