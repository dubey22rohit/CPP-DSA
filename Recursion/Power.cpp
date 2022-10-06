#include <iostream>
using namespace std;

int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    return power(x, y - 1) * x;
}

int powerBetter(int m, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return powerBetter(m * m, n / 2);
    } else {
        return m * powerBetter(m * m, (n - 1) / 2);
    }
}

int main() {
    int pow = power(2, 4);
    int powBetter = powerBetter(2, 9);
    cout << pow << endl;
    cout << powBetter << endl;
    return 0;
}