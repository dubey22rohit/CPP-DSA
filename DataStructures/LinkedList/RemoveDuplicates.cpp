#include <iostream>

#include "CommonFunctions.h"
using namespace std;

void RemoveDuplicates(Node *p) {
    // p is the tail pointer to q, usually it is the other way around.
    Node *q = p->next;
    while (q != NULL) {
        if (p->data != q->data) {
            p = q;
            q = q->next;
        } else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main() {
    int A[] = {3, 5, 5, 8, 8, 8};
    Create(A, sizeof(A) / sizeof(A[0]));
    Display(first);
    cout << endl;
    RemoveDuplicates(first);
    Display(first);
    return 0;
}