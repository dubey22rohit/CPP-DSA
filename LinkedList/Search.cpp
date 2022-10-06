#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void Create(int *A, int n) {
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

struct Node *LinearSearch(struct Node *p, int key) {
    int nodeNum = 0;
    while (p != NULL) {
        if (p->data == key) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct Node *LinSearchMoveToHead(struct Node *p, int key) {
    struct Node *q = NULL;
    while (p != NULL) {
        if (p->data == key) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node *RLinearSearch(struct Node *p, int key) {
    if (p == NULL) {
        return NULL;
    }
    if (p->data == key) {
        return p;
    } else {
        return RLinearSearch(p->next, key);
    }
}

int main() {
    int A[] = {2, 4, 6, 8, 10};
    Create(A, 5);
    Display(first);
    cout << endl;
    struct Node *sa = LinearSearch(first, 6);
    struct Node *rsa = RLinearSearch(first, 6);
    struct Node *mthsa = LinSearchMoveToHead(first, 6);
    printf("Element %d found at address %p\n", *sa, sa);
    printf("Element %d found at address %p using recursion\n", *rsa, rsa);
    printf("Element %d found at address %p using move to head LS\n", *mthsa,
           mthsa);
    cout << "Elements after mthsa : ";
    Display(first);
    //%p for address
    return 0;
}