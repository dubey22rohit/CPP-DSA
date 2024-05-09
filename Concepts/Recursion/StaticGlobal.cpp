#include <iostream>
using namespace std;

int fun1(int n) {
    // No static/global variables
    if (n > 0) {
        return fun1(n - 1) + n;
    }
    return 0;
}

int fun2(int n) {
    // With static variable
    static int x = 0;
    if (n > 0) {
        x++;
        return fun2(n - 1) + x;
    }
    return 0;
}

int main() {
    int r, a;
    r = fun1(5);
    a = fun2(5);
    printf("%d\n", r);
    printf("%d", a);
    return 0;
}