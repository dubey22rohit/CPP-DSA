#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void Create(int *A, int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p) {
    // TC : O(N)
    // SC : O(1)
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void DisplayRecursive(struct Node *p) {
    // TC : O(N) : Just printing and calling itself, printing takes no time.
    // SC : O(N + 1) : +1 for the last call on NULL as well.
    if (p == NULL) {
        return;
    }
    printf("%d ", p->data);
    DisplayRecursive(p->next);
}

int NumNodes(struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int RNumNodes(struct Node *p) {
    if (p == NULL) {
        return 0;
    }
    // Addition done at returning time, even if 1 + RNumNodes(p->next) is
    // written, because for addition to take place, we'll need the value of
    // RNumNodes(p->next) before performing addition, which we'll only get
    // during the returning time.
    return RNumNodes(p->next) + 1;
}

int SumOfNodes(struct Node *p) {
    int sum = 0;
    while (p != NULL) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int RSumOfNodes(struct Node *p) {
    if (p == NULL) {
        return 0;
    }
    return RSumOfNodes(p->next) + p->data;
}

int MaxEleInLL(struct Node *p) {
    int max = INT32_MIN;  // -32768
    while (p != NULL) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int RMaxEleInLL(struct Node *p) {
    if (p == NULL) {
        return INT32_MIN;
    }
    int x = RMaxEleInLL(p->next);
    return x > p->data ? x : p->data;
}

int main() {
    int A[] = {2, 4, 6, 8, 10};
    Create(A, 5);
    Display(first);
    cout << endl;
    DisplayRecursive(first);
    cout << endl;
    cout << "Num Nodes : " << NumNodes(first) << endl;
    cout << "Num Nodes Recursive: " << RNumNodes(first) << endl;
    cout << "Sum Nodes: " << SumOfNodes(first) << endl;
    cout << "Sum Nodes Recursive: " << RSumOfNodes(first) << endl;
    cout << "Max Value: " << MaxEleInLL(first) << endl;
    cout << "Max Value Recursive: " << RMaxEleInLL(first) << endl;

    return 0;
}