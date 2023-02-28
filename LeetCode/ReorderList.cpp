#include <iostream>

#include "ListFunctions.h"
using namespace std;

ListNode* reverseList(ListNode* root) {
    ListNode *p = root, *q = nullptr, *r = nullptr;
    while (p != nullptr) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

void reorderList(ListNode* root) {
    ListNode *rev = reverseList(root), *root1 = root, *root2 = root;
    ListNode* rev1 = rev;
    while (root1 != nullptr) {
    }
}

int main() {
    ListNode* head = takeInputOptimized();
    printLL(head);
    ListNode* reorder = reorderList(head);
    // printLL(reorder);
    return 0;
}