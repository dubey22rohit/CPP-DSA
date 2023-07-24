#include <iostream>
using namespace std;

bool isPalindrome(string s) {
    string ns = "";
    for (int i = 0; i < s.size(); i++) {
        if ((65 <= s[i]) && (s[i] <= 90)) {
            ns.push_back(s[i] + 32);
        } else if ((48 <= s[i]) && (s[i] <= 57)) {
            ns.push_back(s[i]);
        } else if ((97 <= s[i]) && (s[i] <= 122)) {
            ns.push_back(s[i]);
        }
    }

    int i = 0, j = ns.size() - 1;
    while (i <= j) {
        if (ns[i] != ns[j]) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main() { return 0; }