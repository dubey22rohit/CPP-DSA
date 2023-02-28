#include <iostream>

#include "ListFunctions.h"
using namespace std;

ListNode* reverseList(ListNode* head) {
    ListNode *p = head, *q = nullptr, *r = nullptr;
    while (p != nullptr) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

int listLength(ListNode* head) {
    ListNode* temp = head;
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

ListNode* middle(ListNode* root) {
    ListNode* mid = root;
    int len = listLength(root);
    int i = 0;
    while (i < len / 2) {
        cout << "\nCurrent mid value: " << mid->val;
        mid = mid->next;
        i++;
    }
    if (len % 2 == 0) {
        return mid;
    }
    return mid->next;
}

bool isPalindrome(ListNode* root) {
    ListNode* mid = middle(root);
    ListNode* revmid = reverseList(mid);
    ListNode* p = root;

    while (revmid != nullptr) {
        if (p->val != revmid->val) {
            return false;
        }
        revmid = revmid->next;
        p = p->next;
    }
    return true;
}

int main() {
    ListNode* head = takeInputOptimized();
    printLL(head);
    cout << "Is list palindrome?: " << isPalindrome(head);
    return 0;
}