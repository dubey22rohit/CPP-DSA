#include <iostream>

#include "ListFunctions.h"
using namespace std;

ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) {
        return head;
    }
    ListNode *curr = head, *tail = head;
    while (curr != nullptr) {
        if (curr->val == val) {
            tail->next = curr->next;
            curr = curr->next;
        } else {
            tail = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    ListNode* head = takeInputOptimized();
    printLL(head);
    int n;
    cin >> n;
    cout << "\nAfter removing elements: \n";
    ListNode* newHead = removeElements(head, n);
    printLL(head);
    return 0;
}