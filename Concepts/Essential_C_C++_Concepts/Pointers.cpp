#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    int a = 10;
    int *p;
    p = &a;

    cout << a << endl;
    cout << &a << endl;  // prints address of a
    cout << p << endl;   // prints address of a
    cout << *p << endl;  // De-Referencing, prints the value of a

    int B[5] = {1, 2, 3, 4, 5};
    int *q;
    q = B;  //& is not Required, as B(name of the array) itself is the starting
            // address of Array B;, or use this : q = &B[0];
    for (int i = 0; i < 5; i++) {
        // cout << B[i] << endl;
        cout << q[i] << endl;  // Using pointer to access array
    }

    int *r;
    // r = (int *)malloc(5 * sizeof(int));
    r = new int[5];  // Heap array created, dynamic allocation
    r[0] = 5;
    r[1] = 10;
    r[2] = 15;
    r[3] = 20;
    r[4] = 25;

    for (int i = 0; i < 5; i++) {
        cout << r[i] << endl;  // Printing heap array
    }
    // free(r) -> for c
    delete[] r;  // for c++, deallocate heap memory

    int *i;
    char *c;
    float *f;
    double *d;
    struct Rectangle *R;

    cout << sizeof(i) << endl;
    cout << sizeof(c) << endl;
    cout << sizeof(f) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(R) << endl;
    // All the pointers are of 8 bytes, no matter their type

    int e = 500;
    int *pe = &e;

    *pe = 550;  // This is how call by address works, we modify the value of e
                // indirectly using de-referenced pointer.
    cout << e << endl;    // 550
    cout << *pe << endl;  // 550

    return 0;
}