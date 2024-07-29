#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

/**
 * Finds the middle node of a linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @return A pointer to the middle node of the linked list.
 *
 * @throws None
 */
ListNode* findMiddle(ListNode* head) {
  // Declare two pointers, fast and slow, to the head of the list.
  ListNode *fast = head, *slow = head;

  // Continue the loop until either the fast pointer reaches the end of the
  // list or the fast pointer's next node is null.
  while (fast && fast->next) {
    // Move the fast pointer two steps ahead.
    fast = fast->next->next;

    // Move the slow pointer one step ahead.
    slow = slow->next;
  }

  // Return the slow pointer, which will point to the middle node.
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