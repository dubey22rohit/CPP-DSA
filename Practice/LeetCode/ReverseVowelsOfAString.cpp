#include <iostream>
#include <stack>
using namespace std;

bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
        c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }
    return false;
}

string reverseVowels(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (isVowel(s[i])) {
            st.push(s[i]);
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (isVowel(s[i])) {
            s[i] = st.top();
            st.pop();
        }
    }
    return s;
}

int main() {
    string s;
    getline(cin, s);
    string ans = reverseVowels(s);
    cout << ans;
    return 0;
}