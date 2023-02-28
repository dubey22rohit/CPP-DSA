#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool matchingParentheses(char c1, char c2) {
    if (c1 == '(' && c2 == ')') {
        return true;
    } else if (c1 == '{' && c2 == '}') {
        return true;
    } else if (c1 == '[' && c2 == ']') {
        return true;
    }
    return false;
}

bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (st.empty()) {
                return false;
            }
            char tp = st.top();
            if (matchingParentheses(tp, s[i])) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
    }

    if (!st.empty()) {
        return false;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    cout << isValid(s);
    return 0;
}