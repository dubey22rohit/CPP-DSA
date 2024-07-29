#include <iostream>

#include "../Helpers/ListNode.h"

using namespace std;

/**
 * Checks if a linked list has a cycle.
 *
 * @param head A pointer to the head of the linked list.
 * @return True if the linked list has a cycle, false otherwise.
 */
static bool hasCycle(ListNode *head) {
  // Initialize two pointers, fast and slow, to the head of the list.
  ListNode *fast = head, *slow = head;

  // Continue the loop until either the fast pointer reaches the end of the
  // list or the fast pointer's next node is null.
  while (fast && fast->next) {
    // Move the fast pointer two steps ahead.
    fast = fast->next->next;

    // Move the slow pointer one step ahead.
    slow = slow->next;

    // If the slow pointer and the fast pointer meet at the same node, it
    // means there is a cycle in the list.
    if (slow == fast) {
      return true;
    }
  }

  // If the loop completes without finding a cycle, there is no cycle in the
  // list.
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