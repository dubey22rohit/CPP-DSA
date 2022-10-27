#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    if (n < 0 || (n % 10 == 0 && n != 0)) {
        return false;
    }
    int rn = 0;
    while (n > rn) {
        rn = (rn * 10) + (n % 10);
        n /= 10;
    }

    return n == rn || n == rn / 10;
}

int main() {
    int n;
    cin >> n;
    cout << "IS " << n << " "
         << "Palindrome? " << isPalindrome(n);

    // Dry run:
    //  n = 1221
    // rn = 0

    // rn = 0 + 1 = 1
    // n = 122

    // rn = 10 + 2 = 12
    // n = 12

    // rn == n ? true

    // EXAMPLE 2:

    // n = 12321
    // rn = 0

    // rn = 0 + 1 = 1
    // n = 1232

    // rn = 10 + 2 = 12
    // n = 123

    // rn = 120 + 3 = 123
    // n = 12
    //  n == rn / 10 ? true

    return 0;
}