#include <iostream>
using namespace std;

void fun(int *Arr, int n) {
    cout << sizeof(Arr) / sizeof(int)
         << endl;  // Will print 2 as Arr is passed as a pointer, hence
                   // sizeof(Arr) will be 8(size of a pointer) and sizeof(int)
                   // is 4;
    // for (int a : Arr) {
    //     cout << a << endl;Can't use foreach loop since Arr is a pointer
    // }
    for (int i = 0; i < n; i++) {
        cout << Arr[i] << endl;
    }
    Arr[4] =
        200;  // Will change the array in main as array is passed by address
}

// int [] funReturningArray(int size)
int *funReturningArray(int size) {
    int *p;
    p = new int[size];

    for (int i = 0; i < size; i++) {
        p[i] = i * 10;
    }

    return p;
}

int main() {
    int A[] = {2, 4, 6, 8, 10};
    int n = 5;
    fun(A, n);
    cout << sizeof(A) / sizeof(int) << endl;
    for (int x : A) {
        cout << x << endl;
    }
    cout << endl << endl;

    int *ptr, sz = 7;
    ptr = funReturningArray(sz);

    for (int i = 0; i < sz; i++) {
        cout << ptr[i] << endl;
    }

    return 0;
}