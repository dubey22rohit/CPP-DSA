#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

// https://leetcode.com/problems/add-two-numbers/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* dummy = new ListNode();
  ListNode* temp = dummy;
  int carry = 0;
  while (carry || l1 || l2) {
    int sum = 0;
    if (l1) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      sum += l2->val;
      l2 = l2->next;
    }

    sum += carry;
    carry = sum / 10;
    ListNode* node = new ListNode(sum % 10);
    temp->next = node;
    temp = temp->next;
  }
  return dummy->next;
}

int main() { return 0; }