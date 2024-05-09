#include <iostream>
using namespace std;

bool isPalindrome(string s) {
    string cmp;
    for (int i = 0; i < s.length(); i++) {
        if ((65 <= s[i]) && (s[i] <= 90)) {
            cmp.push_back(s[i] + 32);
        } else if ((97 <= s[i]) && (s[i] <= 122)) {
            cmp.push_back(s[i]);
        } else if ((48 <= s[i]) && (s[i] <= 57)) {
            cmp.push_back(s[i]);
        }
    }

    int i = 0, j = cmp.length() - 1;
    while (i <= j) {
        if (cmp[i] != cmp[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    string s = "0P";
    cout << "IS PALINDROME: " << isPalindrome(s);
    return 0;
}
