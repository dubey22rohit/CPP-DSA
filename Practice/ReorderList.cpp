#include <iostream>

#include "ListNode.h"
using namespace std;

void reorderList(ListNode* head) {
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *second = slow->next, *prev = nullptr;
    slow->next = nullptr;
    while (second) {
        ListNode* tmp = second->next;
        second->next = prev;
        prev = second;
        second = tmp;
    }

    ListNode* first = head;
    second = prev;
    while (second) {
        ListNode *tmp1 = first->next, *tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
    }
}

int main() {
    ListNode* head = createList();
    printList(head);
    reorderList(head);
    printList(head);
    return 0;
}