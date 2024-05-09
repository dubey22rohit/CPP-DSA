#include <math.h>

#include <iostream>

#include "ListFunctions.h"

using namespace std;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *ans = NULL, *ansp = NULL, *nn = NULL;
  int s1, s2, carry = 0;
  while (l1 || l2 || carry != 0) {
    if (l1) {
      s1 = l1->val;
      l1 = l1->next;
    } else {
      s1 = 0;
    }

    if (l2) {
      s2 = l2->val;
      l2 = l2->next;
    } else {
      s2 = 0;
    }

    int sum = s1 + s2 + carry;
    carry = sum / 10;
    int rem = sum % 10;

    nn = new ListNode(rem);
    if (!ans) {
      ans = nn;
      ansp = ans;
    } else {
      ansp->next = nn;
      ansp = ansp->next;
    }
  }
  return ans;
}

int main() {
  ListNode *l1 = takeInputOptimized();
  ListNode *l2 = takeInputOptimized();
  cout << "List 1: ";
  printLL(l1);
  cout << endl;
  cout << "List 2: ";
  printLL(l2);
  cout << endl;
  ListNode *ans = addTwoNumbers(l1, l2);
  cout << "List ans: ";
  printLL(ans);
  cout << endl;
  return 0;
}
