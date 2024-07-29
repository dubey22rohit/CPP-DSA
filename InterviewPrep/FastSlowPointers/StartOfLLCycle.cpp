#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

/**
 * Finds the length of the cycle in a linked list.
 *
 * @param slow A pointer to a node in the linked list.
 * @return The length of the cycle.
 */
static int findCycleLength(ListNode* slow) {
  // Initialize a pointer to the current node and initialize the cycle length to
  // 0.
  ListNode* curr = slow;
  int cycleLength = 0;

  // Traverse the linked list until the slow pointer meets itself.
  do {
    // Move the current pointer to the next node.
    curr = curr->next;
    // Increment the cycle length.
    cycleLength++;
  } while (slow != curr);

  // Return the length of the cycle.
  return cycleLength;
}

/**
 * Finds the start of the cycle in a linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @param cycleLength The length of the cycle.
 * @return A pointer to the start of the cycle.
 */
static ListNode* findStart(ListNode* head, int cycleLength) {
  // Initialize two pointers, p1 and p2, to the head of the list.
  ListNode *p1 = head, *p2 = head;

  // Move p2 to the start of the cycle.
  while (cycleLength--) {
    p2 = p2->next;
  }

  // Move both pointers until they meet at the start of the cycle.
  while (p1 != p2) {
    p1 = p1->next;
    p2 = p2->next;
  }

  // Return the start of the cycle.
  return p1;
}

/**
 * Finds the start of the cycle in a linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @return A pointer to the start of the cycle.
 *
 * This function uses the two pointer technique to find the start of the cycle.
 * It uses two pointers, 'fast' and 'slow', to traverse the linked list.
 * The 'fast' pointer is moved two steps ahead of the 'slow' pointer at each
 * step. When the 'fast' pointer meets the 'slow' pointer, it means that a cycle
 * exists. The function then calls 'findCycleLength' to find the length of the
 * cycle and uses 'findStart' to find the start of the cycle.
 */
static ListNode* findCycleStart(ListNode* head) {
  int cycleLength = 0;
  ListNode *fast = head, *slow = head;
  while (fast && fast->next) {
    // Move 'fast' two steps ahead.
    fast = fast->next->next;
    // Move 'slow' one step ahead.
    slow = slow->next;
    // If 'fast' and 'slow' meet, it means a cycle exists.
    if (fast == slow) {
      // Find the length of the cycle.
      cycleLength = findCycleLength(slow);
      break;
    }
  }
  // Find the start of the cycle.
  return findStart(head, cycleLength);
}

// As we know, finding the cycle in a LinkedList with ‘N’ nodes and also finding
// the length of the cycle requires 𝑂(𝑁)
// Also, as we saw in the above algorithm, we will need O(N) to find the
// start of the cycle.Therefore, the overall time complexity of our algorithm
// will be O(N).

// The algorithm runs in constant space O(1).

int main() {
  ListNode* head = new ListNode(1);
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