#include <iostream>

#include "Node.h"
using namespace std;

Node* reverseList(Node* head) {
    Node *p = head, *q = nullptr, *r = nullptr;
    while (p != nullptr) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

int main() {
    Node* head = createList();
    printList(head);
    cout << std::endl;
    Node* newHead = reverseList(head);
    printList(newHead);
    return 0;
}