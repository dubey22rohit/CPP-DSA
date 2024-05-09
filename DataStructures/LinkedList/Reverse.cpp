#include <iostream>

#include "CommonFunctions.h"
using namespace std;

// 1)By changing elements
void Reverse1(Node* p) {
    int* A;
    A = new int[5];
    int i = 0;
    while (p != NULL) {
        A[i++] = p->data;
        p = p->next;
    }
    p = first;
    i--;
    while (p != NULL) {
        p->data = A[i--];
        p = p->next;
    }
}

// 2) Reversing Links (Using sliding pointers)
void Reverse2(struct Node* p) {
    Node *q, *r;
    q = NULL;
    r = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// 3) Using Recursion(While returning phase)
void Reverse3(struct Node* q, struct Node* p) {
    if (p != NULL) {
        Reverse3(p, p->next);
        p->next = q;
    } else {
        first = q;
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    Node* q;
    q = NULL;
    Create(A, sizeof(A) / sizeof(A[0]));
    Display(first);
    cout << endl;
    // Reverse1(first);
    // Reverse2(first);
    Reverse3(q, first);
    Display(first);

    return 0;
}