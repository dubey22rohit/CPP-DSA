#include <iostream>

#include "ListNode.h"
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head->next == NULL) {
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (n--) {
        fast = fast->next;
    }
    if (fast == NULL) {
        return head->next;
    }
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;

    return head;
}

int main() {
    ListNode* head = createList();
    printList(head);

    int n;
    cin >> n;

    cout << "\nAfter removing nth from end:\n";

    ListNode* newList = removeNthFromEnd(head, n);
    printList(newList);
    return 0;
}