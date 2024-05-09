#include <iostream>
using namespace std;

// question mentions positive integers
int recursiveMultiply(int x, int y) {
    if (x <= 0 || y <= 0) {
        return 0;
    }
    return x + recursiveMultiply(x, y - 1);
}

int main() {
    int x, y;
    cin >> x >> y;
    int mul = recursiveMultiply(x, y);
    cout << mul;
    return 0;
}