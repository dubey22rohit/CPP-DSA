#include <iostream>
using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string/
// INCOMPLETE
string reverseWords(string s) {
  int left = 0, right = s.length() - 1;
  string temp = "";
  string ans = "";
  while (left <= right) {
    char ch = s[left];
    if (ch != ' ') {
      temp += ch;
    } else {
      if (ans != "") {
        ans = temp + " " + ans;
      } else {
        ans = temp;
      }
      temp = "";
    }
    left++;
  }

  if (temp != "") {
    if (ans != "") {
      ans = temp + " " + ans;
    } else {
      ans = temp;
    }
  }
  return ans;
}

int main() { return 0; }