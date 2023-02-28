#include <iostream>
#include <unordered_map>

#include "Node.h"
using namespace std;

// Remove duplicated from an unsorted list
void removeDuplicates(Node* head) {
    Node *t = head, *prev = head;
    unordered_map<int, int> hm;
    while (t->next != nullptr) {
        hm[t->data]++;
        if (hm[t->data] > 1) {
            prev->next = t->next;
            t = t->next;
            continue;
        }
        prev = t;
        t = t->next;
    }
}

int main() {
    Node* head = createList();
    printList(head);
    removeDuplicates(head);
    printList(head);
    return 0;
}