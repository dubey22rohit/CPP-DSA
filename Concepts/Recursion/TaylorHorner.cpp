#include <iostream>
using namespace std;

double TaylorHornerRecursion(int x, int n) {
    static double s = 1;
    if (n == 0) {
        return s;
    }
    s = 1 + x * s / n;
    return TaylorHornerRecursion(x, n - 1);
}

double TaylorHornerLoop(int x, int n) {
    // double s = 1;
    // for (; n > 0; n--) {
    //     s = 1 + x * s / n;
    // }
    // return s;
    double s = 1;
    double num = 1;
    double den = 1;
    for (int i = 1; i <= n; i++) {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

int main() {
    cout << "Taylor Horner Loop " << TaylorHornerLoop(1, 10) << endl;
    cout << "Taylor Horner Recursion " << TaylorHornerRecursion(1, 10) << endl;
    return 0;
}