#include <iostream>

#include "ListFunctions.h"
using namespace std;

ListNode* removeElements(ListNode* head, int val) {
    ListNode *p = head, *q = new ListNode(-1);
    while (p != nullptr && p->next != nullptr) {
        if (p->val == val) {
            q->next = p->next;
            p = p->next;
        }
        q = p;
        if (p->next != nullptr) {
            p = p->next;
        }
    }
    if (p->val == val) {
        q->next = nullptr;
    }
    return head;
}

int main() {
    ListNode* head = takeInputOptimized();
    int val;
    cout << "\nEnter element to remove: ";
    cin >> val;
    ListNode* ans = removeElements(head, val);
    cout << "List after removing " << val << ":\n";
    printLL(ans);
    return 0;
}