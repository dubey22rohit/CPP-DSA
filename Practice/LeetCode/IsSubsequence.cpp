#include <iostream>
#include <unordered_map>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0;
    int j = 0;
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    if (i == s.length()) {
        return true;
    }
    return false;
}

int main() {
    string s;
    string t;

    cout << "Enter string s: ";
    cin >> s;
    cout << endl;

    cout << "Enter string t: ";
    cin >> t;
    cout << endl;

    cout << "Is s a subsequence of t?: " << isSubsequence(s, t);

    return 0;
}