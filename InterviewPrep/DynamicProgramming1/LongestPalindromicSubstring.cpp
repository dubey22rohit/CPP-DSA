#include <iostream>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-substring/
string longestPalindrome(string s) {
  int maxLen = 0;
  string result = "";
  for (int i = 0; i < s.size(); i++) {
    int prev = i;
    int next = i;
    while (prev >= 0 && next < s.size() && s[prev] == s[next]) {
      if (next - prev + 1 > maxLen) {
        maxLen = next - prev + 1;
        result = s.substr(prev, next - prev + 1);
      }
      prev--;
      next++;
    }

    prev = i;
    next = i + 1;
    while (prev >= 0 && next < s.size() && s[prev] == s[next]) {
      if (next - prev + 1 > maxLen) {
        maxLen = next - prev + 1;
        result = s.substr(prev, next - prev + 1);
      }
      prev--;
      next++;
    }
  }
  return result;
}

int main() { return 0; }