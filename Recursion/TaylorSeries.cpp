#include <iostream>
using namespace std;

// For finding pow(e,x);
// e**x = 1 + x/1 + pow(x,2)/2! + pow(x,3)/3! + pow(x,4)/4! + ....... + n terms
double taylor(int x, int n) {
    static double p = 1, f = 1;
    double r;
    if (n == 0) {
        return 1;
    }
    r = taylor(x, n - 1);
    p *= x;
    f *= n;
    return r + (p / f);
}

int main() {
    // Calculating e**2 with 15 terms(more value == more precise value)
    cout << taylor(2, 15);
    return 0;
}