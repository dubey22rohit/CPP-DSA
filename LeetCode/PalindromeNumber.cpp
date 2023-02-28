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

    return 0;
}