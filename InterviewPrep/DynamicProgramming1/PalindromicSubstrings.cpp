#include <iostream>
using namespace std;

// https://leetcode.com/problems/palindromic-substrings/
int countSubstrings(string s) {
  int substrs = 0;
  for (int i = 0; i < s.size(); i++) {
    int prev = i;
    int next = i;
    while (prev >= 0 && next < s.size() && s[prev] == s[next]) {
      substrs++;
      prev--;
      next++;
    }

    prev = i;
    next = i + 1;
    while (prev >= 0 && next < s.size() && s[prev] == s[next]) {
      substrs++;
      prev--;
      next++;
    }
  }

  return substrs;
}

int main() {
  cout << countSubstrings("aaa");
  return 0;
}