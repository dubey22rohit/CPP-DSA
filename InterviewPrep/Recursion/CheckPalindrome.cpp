#include <iostream>
using namespace std;

bool checkPalindrome2(string s, int si) {
  if (si >= s.size() / 2) {
    return true;
  }
  if (s[si] != s[s.size() - si - 1]) {
    return false;
  }
  return checkPalindrome2(s, si + 1);
}
bool checkPalindrome(string s, int si, int ei) {
  if (si >= ei) {
    return true;
  }
  if (s[si] != s[ei]) {
    return false;
  }
  return checkPalindrome(s, si + 1, ei - 1);
}

int main() {
  string s;
  getline(cin, s);
  cout << checkPalindrome(s, 0, s.size() - 1) << endl;
  cout << checkPalindrome2(s, 0) << endl;
  return 0;
}