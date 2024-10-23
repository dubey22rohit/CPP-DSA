#include <iostream>
#include <stack>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/
bool isValid(string s) {
  stack<char> st;
  string openingPt = "([{";
  string closingPt = ")]}";

  unordered_map<char, char> matchingPt;
  matchingPt[')'] = '(';
  matchingPt[']'] = '[';
  matchingPt['}'] = '{';

  for (char c : s) {
    if (openingPt.find(c) < openingPt.length()) {
      st.push(c);
    } else if (closingPt.find(c) < closingPt.length()) {
      if (st.empty()) {
        return false;
      }
      if (matchingPt[c] == st.top()) {
        st.pop();
      } else {
        return false;
      }
    }
  }
  return st.empty();
}

int main() { return 0; }