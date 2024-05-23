#include <iostream>
#include <unordered_map>
using namespace std;

// Longest Substring with K Distinct Characters (medium)
// Given a string, find the length of the longest substring in it with no more
// than K distinct characters.

static int findLength(const string &str, int k) {
  unordered_map<char, int> hm;
  int maxLength = INT_MIN;
  int windowStart = 0;
  for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd) {
    hm[str[windowEnd]]++;
    while (hm.size() > k) {
      hm[str[windowStart]]--;
      if (hm[str[windowStart]] == 0) {
        hm.erase(str[windowStart]);
      }
      windowStart++;
    }
    maxLength = max(maxLength, windowEnd - windowStart + 1);
  }
  return maxLength;
}

int main() {
  string str;
  getline(cin, str);
  int k;
  cin >> k;
  int maxLength = findLength(str, k);
  cout << maxLength;
  return 0;
}