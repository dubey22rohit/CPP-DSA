#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    string ob = "[{(";
    string cb = ")}]";
    unordered_map<char, char> hm;
    hm[']'] = '[';
    hm['}'] = '{';
    hm[')'] = '(';
    stack<char> st;
    for (auto c : s) {
        if (ob.find(c) < ob.length()) {
            st.push(c);
        } else if (cb.find(c) < cb.length()) {
            if (st.empty()) {
                return false;
            }
            if (st.top() == hm[c]) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() { return 0; }