#include <iostream>

#include "ListFunctions.h"
using namespace std;

/**
 * * Can be more optimized
 * ! Current runtime: 18ms (beats 14.97%)
 * * Current memory: 11.6mb (beats 84.88%)
 */
ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode *curr = head, *tail = head;
    while (curr->next != nullptr) {
        curr = curr->next;
        if (tail->val == curr->val) {
            tail->next = curr->next;
            continue;
        }
        tail = tail->next;
    }
    return head;
}

int main() {
    ListNode* head = takeInputOptimized();
    printLL(head);
    cout << endl;
    ListNode* ans = deleteDuplicates(head);
    printLL(ans);
    return 0;
}