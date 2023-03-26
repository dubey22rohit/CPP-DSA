#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// TC: O(n) : traversing string and comparing brackets(which is constant time)
// SC: O(n) : storing the entire string in the stack(worst case)eg: (((((

bool balancedBrackets(string s) {
    string openingBrackets = "{[(";
    string closingBrackets = "}])";
    unordered_map<char, char> matchingBraces;
    matchingBraces['}'] = '{';
    matchingBraces[')'] = '(';
    matchingBraces[']'] = '[';
    stack<char> st;
    for (auto c : s) {
        if (openingBrackets.find(c) < openingBrackets.length()) {
            st.push(c);
        } else if (closingBrackets.find(c) < closingBrackets.length()) {
            if (st.size() == 0) {
                return false;
            }
            if (st.top() == matchingBraces[c]) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.size() == 0;
}

int main() {
    string s;
    getline(cin, s);
    cout << (balancedBrackets(s) ? "balanced" : "unbalanced");
    return 0;
}