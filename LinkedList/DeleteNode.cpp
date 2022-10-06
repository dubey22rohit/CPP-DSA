#include <iostream>

#include "CommonFunctions.h"
using namespace std;

void DeleteNode(struct Node* p, int pos) {
    if (pos == 0) {
        first = first->next;
        return;
    }
    int i = 1;
    Node* q = NULL;
    while (p && i < pos) {
        q = p;
        p = p->next;
        i++;
    }
    if (p) {
        q->next = p->next;
        delete p;
    }
}

int main() {
    int A[] = {2, 4, 6, 8, 10, 12};
    Create(A, sizeof(A) / sizeof(A[0]));
    Display(first);
    cout << endl;
    DeleteNode(first, 6);
    Display(first);
    return 0;
}