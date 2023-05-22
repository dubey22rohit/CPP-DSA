#include <cmath>
#include <iostream>
using namespace std;

// 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) :Formula for geometric sum
double geometricSum(int k) {
    if (k <= 0) {
        return 1;
    }
    return (1 / pow(2, k)) + geometricSum(k - 1);
}

int main() {
    int n;
    cin >> n;
    cout << geometricSum(n);
    return 0;
}