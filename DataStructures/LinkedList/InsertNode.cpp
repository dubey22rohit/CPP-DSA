#include <iostream>

#include "CommonFunctions.h"

using namespace std;

void Insert(struct Node *p, int pos, int data) {
    struct Node *nn;
    nn = (struct Node *)malloc(sizeof(struct Node));
    nn->data = data;
    if (pos == 0) {
        nn->next = first;
        first = nn;
        return;
    }
    for (int i = 0; i < pos - 1 && p; i++) {
        p = p->next;
    }
    if (p) {
        nn->next = p->next;
        p->next = nn;
    }
}

void InsertInSortedLL(struct Node *p, int ele) {
    struct Node *nn, *q = NULL;
    nn = (struct Node *)malloc(sizeof(struct Node));
    nn->data = ele;
    nn->next = NULL;

    if (first == NULL) {
        first = nn;
    } else {
        while (p && p->data < ele) {
            q = p;
            p = p->next;
        }
        if (p == first) {
            nn->next = first;
            first = nn;
        } else {
            nn->next = q->next;
            q->next = nn;
        }
    }
}

int main() {
    int A[] = {2, 4, 6, 8, 10, 12};
    Create(A, sizeof(A) / sizeof(A[0]));
    Display(first);
    cout << endl;
    // Insert(first, 0, 15);
    // Display(first);
    // cout << endl;
    // Insert(first, 4, 25);
    // Display(first);
    // cout << endl;
    // Insert(first, 8, 35);
    // Display(first);
    InsertInSortedLL(first, 11);
    InsertInSortedLL(first, 1);
    InsertInSortedLL(first, 15);
    Display(first);
    return 0;
}