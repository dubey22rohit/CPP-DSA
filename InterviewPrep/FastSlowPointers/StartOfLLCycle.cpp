#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

static int findCycleLength(ListNode* slow) {
  ListNode* curr = slow;
  int cycleLength = 0;

  do {
    curr = curr->next;
    cycleLength++;
  } while (slow != curr);

  return cycleLength;
}

static ListNode* findStart(ListNode* head, int cycleLength) {
  ListNode *p1 = head, *p2 = head;

  while (cycleLength--) {
    p2 = p2->next;
  }

  while (p1 != p2) {
    p1 = p1->next;
    p2 = p2->next;
  }

  return p1;
}

static ListNode* findCycleStart(ListNode* head) {
  int cycleLength = 0;
  ListNode *fast = head, *slow = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      cycleLength = findCycleLength(slow);
      break;
    }
  }
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