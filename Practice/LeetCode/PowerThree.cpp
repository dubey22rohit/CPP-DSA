#include <iostream>
using namespace std;

/**
 * *Optimized
 * *Runtime 15ms(beats 92%)
 * * Memory 5.8mb(beats 96%)
 */

bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    while (n > 1) {
        if (n % 3 != 0) {
            return false;
        }
        n /= 3;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    bool ans = isPowerOfThree(n);
    cout << ans;
    return 0;
}