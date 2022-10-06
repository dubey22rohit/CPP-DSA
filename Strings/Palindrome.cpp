#include <iostream>
using namespace std;

bool isPalindrome(char *c) {
    int i = 0, j = 0;
    while (c[j] != '\0') {
        j++;
    }
    j -= 1;
    while (i <= j) {
        if (c[i] != c[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    char str[] = "racecar";
    char str2[] = "def not palindrome";
    cout << "Is str palindrome? : " << isPalindrome(str) << endl;
    cout << "Is str2 palindrome? : " << isPalindrome(str2);
    return 0;
}