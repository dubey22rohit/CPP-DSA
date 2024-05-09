#include <iostream>

#include "ListFunctions.h"
using namespace std;

ListNode* listMid(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

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

bool isPalindrome(ListNode* head) {
    ListNode* mid = listMid(head);
    ListNode* rev = reverseLL(mid);
    ListNode* fwd = head;
    while (rev != nullptr) {
        if (fwd->data != rev->data) {
            return false;
        }
        fwd = fwd->next;
        rev = rev->next;
    }
    return true;
}

bool isPalindromRecursive(ListNode* head) {
    return isPalindromRecursiveHelper(head, head);
}

bool isPalindromRecursiveHelper(ListNode* lnode, ListNode* rnode) {}

int main() {
    ListNode* head = takeInput();
    printLL(head);
    cout << "Palindrome?: " << isPalindrome(head);
    return 0;
}