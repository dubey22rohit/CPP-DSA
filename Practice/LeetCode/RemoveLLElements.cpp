#include <iostream>

#include "ListFunctions.h"

using namespace std;
/*
!INCOMPLETE
*/
ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr && head->val == val) {
        return nullptr;
    }

    ListNode *curr = head, *tail = head;
    while (curr->next != nullptr) {
        if (head->val == val) {
            head = head->next;
            curr = head;
            tail = head;
            continue;
        }
        curr = curr->next;
        if (curr->val == val) {
            tail->next = curr->next;
            curr = curr->next;
        }
        tail = tail->next;
    }
    return head;
}

int main() {
    ListNode* head = takeInputOptimized();
    printLL(head);
    cout << endl;
    int val;
    cin >> val;
    ListNode* newHead = removeElements(head, val);
    printLL(newHead);

    return 0;
}