#include <iostream>
using namespace std;

int main() {
    int *p = new int[5];
    int *q = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        p[i] = i * 5;
    }

    // Increasing the size of the dynamic array
    for (int i = 0; i < 5; i++) {
        q[i] = p[i];
    }

    delete[] p;  // De-allocates the heap memory, the pointer is not destroyed
    p = q;
    q = NULL;

    for (int i = 0; i < 5; i++) {
        cout << p[i] << " ";
    }

    return 0;
}