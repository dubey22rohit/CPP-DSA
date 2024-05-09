#include <iostream>
using namespace std;
// 0 1 1 2 3 5 8 13 21

int fibMemoized(int n) {
    static int F[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    if (n <= 1) {
        F[n] = n;
        return n;
    }

    if (F[n - 2] == -1) {
        F[n - 2] = fibMemoized(n - 2);
    }

    if (F[n - 1] == -1) {
        F[n - 1] = fibMemoized(n - 1);
    }

    F[n] = F[n - 2] + F[n - 1];
    cout << "CURRENT VALUE OF STATIC ARRAY :\n";
    for (int i = 0; i < sizeof(F) / sizeof(F[0]); i++) {
        cout << F[i] << " ";
    }
    return F[n - 2] + F[n - 1];
}

int fibRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibRecursive(n - 2) + fibRecursive(n - 1);
}

int fibLoop(int n) {
    int t0 = 0, t1 = 1, s;
    if (n <= 1) {
        return n;
    }
    for (int i = 2; i <= n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int main() {
    cout << "Fib Loop " << fibLoop(8) << endl;
    cout << "Fib Recursive " << fibRecursive(8) << endl;
    cout << "Fib Recursive Memoized \n" << fibMemoized(8) << endl;

    return 0;
}