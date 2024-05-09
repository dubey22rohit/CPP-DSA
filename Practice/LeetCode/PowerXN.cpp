#include <iostream>
using namespace std;

double myPow(double x, int n) {
    if (n == INT_MAX) {
        return (x == 1) ? 1 : (x == -1) ? -1 : 0;
    }
    if (n == INT_MIN) {
        return (x == 1 || x == -1) ? 1 : 0;
    }
    double ans = 1;
    if (n >= 0) {
        while (n > 0) {
            ans *= x;
            n--;
        }
    } else {
        n = -n;
        while (n > 0) {
            ans *= x;
            n--;
        }
        ans = 1 / ans;
    }
    return ans;
}

int main() {
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n);
    return 0;
}