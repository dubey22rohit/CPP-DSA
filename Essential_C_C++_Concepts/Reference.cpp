#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int &r = a;  // Must be initialize with declaration

    cout << a << endl;
    r++;
    cout << a << endl;  // 11
    cout << r << endl;  // 11

    int b = 25;
    r = b;  // Now a will be 25; r is NOT a reference to b.

    cout << a << endl;  // 25
    return 0;
}