#include <iostream>
using namespace std;

int countZeroes(int n) {
    if (n <= 9) {
        if (n == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    int rem = n % 10;
    int count = 0;
    if (rem == 0) {
        count = 1;
    }
    return count + countZeroes(n / 10);
}

int main() {
    int n;
    cin >> n;
    cout << countZeroes(n);
    return 0;
}