#include <iostream>

#include "../Helpers/ListNode.h"
using namespace std;

// https://leetcode.com/problems/intersection-of-two-linked-lists/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  int lenA = 0, lenB = 0;
  ListNode *aCopy = headA;
  while (aCopy) {
    lenA++;
    aCopy = aCopy->next;
  }

  ListNode *bCopy = headB;
  while (bCopy) {
    lenB++;
    bCopy = bCopy->next;
  }

  aCopy = headA;
  bCopy = headB;

  while (lenA > lenB) {
    lenA--;
    aCopy = aCopy->next;
  }

  while (lenB > lenA) {
    lenB--;
    bCopy = bCopy->next;
  }

  while (aCopy && bCopy) {
    if (aCopy == bCopy) {
      return aCopy;
    }
    aCopy = aCopy->next;
    bCopy = bCopy->next;
  }
  return NULL;
}

int main() { return 0; }