#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
}

ListNode*
reverseList(ListNode* head) {
    ListNode *q = NULL, *r = NULL;
    ListNode* rev = head;
    while (rev != NULL) {
        r = q;
        q = rev;
        rev = rev->next;
        q->next = rev;
    }
    return rev;
}

int main() { return 0; }