#include <iostream>
using namespace std;

void swapByValue(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swapByAddress(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapByReference(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swapByReferenceAddress(int &x, int *y) {
    int temp;
    temp = x;
    x = *y;
    *y = temp;
}

int main() {
    int a = 10;
    int b = 20;
    cout << "Before passing by value : " << a << " " << b << endl;
    swapByValue(a, b);
    cout << "After passing by value : " << a << " " << b << endl << endl;

    a = 10;
    b = 20;
    cout << "Before passing by address : " << a << " " << b << endl;
    swapByAddress(&a, &b);
    cout << "After passing by address : " << a << " " << b << endl << endl;

    a = 10;
    b = 20;
    cout << "Before passing by reference : " << a << " " << b << endl;
    swapByReference(a, b);
    cout << "After passing by reference : " << a << " " << b << endl << endl;

    a = 10;
    b = 20;
    cout << "Before passing by referenceAddress : " << a << " " << b << endl;
    swapByReferenceAddress(a, &b);
    cout << "After passing by referenceAddress : " << a << " " << b << endl
         << endl;

    return 0;
}