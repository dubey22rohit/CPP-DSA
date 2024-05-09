#include <iostream>

#include "CommonFunctions.h"
using namespace std;

bool CheckSorted(struct Node* p) {
    while (p->next != NULL) {
        if (p->data > p->next->data) {
            return false;
        }
        p = p->next;
    }
    return true;
}

int main() {
    int A[] = {-1, 2, 4, 6, 8, 10, 12};
    Create(A, sizeof(A) / sizeof(A[0]));
    Display(first);
    cout << endl;
    cout << "Is sorted ? " << CheckSorted(first);
    return 0;
}