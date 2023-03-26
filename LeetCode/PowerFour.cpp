#include <iostream>
using namespace std;

bool isPowerOfFour(int n) {
    if (n <= 0) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    while (n > 1) {
        if (n % 4 != 0) {
            return false;
        }
        n /= 4;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    bool ans = isPowerOfFour(n);
    cout << ans;
    return 0;
}