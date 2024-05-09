#include <iostream>
using namespace std;

int power(int m, int n) {
    if (n == 0) {
        return 1;
    }

    return m * power(m, n - 1);
}

int power2(int m, int n) {
    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        return power2(m * m, n / 2);
    } else {
        return m * power2(m * m, (n - 1) / 2);
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << power(m, n) << endl;
    cout << power2(m, n) << endl;

    return 0;
}