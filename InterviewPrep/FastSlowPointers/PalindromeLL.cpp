#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

/**
 * Reverses a linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @return A pointer to the head of the reversed linked list.
 */
ListNode* reverseLL(ListNode* head) {
  // Use three pointers technique to reverse the linked list.
  ListNode *p = head, *q = nullptr, *r = nullptr;

  // Iterate through the linked list and reverse the pointers.
  while (p) {
    // Store the next pointer of the current node.
    r = q;

    // Move the current pointer to the next node.
    q = p;

    // Move the new current pointer to the next node.
    p = p->next;

    // Update the next pointer of the current node to the reversed list.
    q->next = r;
  }

  // Return the head of the reversed linked list.
  return q;
}

/**
 * Checks if a linked list is a palindrome.
 *
 * @param head A pointer to the head of the linked list.
 * @return True if the linked list is a palindrome, false otherwise.
 */
bool isPalindrome(ListNode* head) {
  // Use two pointers technique to find the middle of the linked list.
  ListNode *fast = head, *slow = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }

  // Reverse the second half of the linked list.
  slow = reverseLL(slow);
  fast = head;

  // Compare the first and second halves of the linked list.
  while (slow && fast) {
    // If the values at the current position do not match, the linked list
    // is not a palindrome.
    if (slow->val != fast->val) {
      return false;
    }
    slow = slow->next;
    fast = fast->next;
  }

  // If all values match, the linked list is a palindrome.
  return true;
}

int main() {
  ListNode* head = createList();
  cout << isPalindrome(head);
  return 0;
}