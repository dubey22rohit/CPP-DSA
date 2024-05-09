#include <iostream>

#include "ListNode.h"
using namespace std;

ListNode* reverseLL(ListNode* head) {
    ListNode *p = head, *q = nullptr, *r = nullptr;
    while (p != nullptr) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    return q;
}

int main() {
    ListNode* head = createList();
    printList(head);
    ListNode* reversedList = reverseLL(head);
    printList(reversedList);
    return 0;
}