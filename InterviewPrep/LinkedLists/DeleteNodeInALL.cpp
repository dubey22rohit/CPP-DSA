#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

// Very cool question.
// https://leetcode.com/problems/delete-node-in-a-linked-list/

void deleteNode(ListNode* node) {
  node->val = node->next->val;
  node->next = node->next->next;
}

int main() { return 0; }