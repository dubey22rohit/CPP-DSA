#include <iostream>
#include <unordered_map>
using namespace std;

// No-repeat Substring (hard)
// Given a string, find the length of the longest substring which has no
// repeating characters.

static int findLength(const string &str) {
  unordered_map<char, int> hm;
  int maxLength = INT_MIN, windowStart = 0;
  for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd) {
    char rightChar = str[windowEnd];
    if (hm.find(rightChar) != hm.end()) {
      windowStart = max(windowStart, hm[rightChar] + 1);
    }
    hm[rightChar] = windowEnd;
    maxLength = max(maxLength, windowEnd - windowStart + 1);
  }
  return maxLength;
}

int main() {
  string str;
  getline(cin, str);
  int maxLength = findLength(str);
  cout << maxLength;
  return 0;
}