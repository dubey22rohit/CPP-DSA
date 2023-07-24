#include <math.h>

#include <iostream>

#include "ListFunctions.h"

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* sl = nullptr;
    ListNode* slp = sl;
    ListNode* nn = nullptr;
    int carry = 0;
    while (l1 != nullptr && l2 != nullptr) {
        int cs = l1->val + l2->val + carry;
        if (cs >= 10) {
            carry = 1;
            cs %= 10;
        } else {
            carry = 0;
        }
        nn = new ListNode(cs);
        if (sl == nullptr) {
            sl = nn;
            slp = sl;
        } else {
            slp->next = nn;
            slp = slp->next;
        }
        cs = 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != nullptr) {
        int cs = l1->val + carry;
        if (cs >= 10) {
            carry = 1;
            cs %= 10;
        } else {
            carry = 0;
        }
        nn = new ListNode(cs);
        slp->next = nn;
        slp = slp->next;
        l1 = l1->next;
    }
    while (l2 != nullptr) {
        int cs = l2->val + carry;
        if (cs >= 10) {
            carry = 1;
            cs %= 10;
        } else {
            carry = 0;
        }
        nn = new ListNode(cs);
        slp->next = nn;
        slp = slp->next;
        l2 = l2->next;
    }
    if (carry == 1) {
        nn = new ListNode(1);
        slp->next = nn;
        slp = slp->next;
    }
    return sl;
}

int main() {
    ListNode* l1 = takeInputOptimized();
    ListNode* l2 = takeInputOptimized();
    cout << "List 1: ";
    printLL(l1);
    cout << endl;
    cout << "List 2: ";
    printLL(l2);
    cout << endl;
    ListNode* ans = addTwoNumbers(l1, l2);
    cout << "List ans: ";
    printLL(ans);
    cout << endl;
    return 0;
}