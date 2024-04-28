#include <iostream>
#include <unordered_map>
using namespace std;

// Longest Substring with K Distinct Characters (medium)
int findLength(string &str, int k) {
  int maxLen = 0, windowStart = 0;
  unordered_map<char, int> hm;
  for (int windowEnd = 0; windowEnd < str.length(); ++windowEnd) {
    hm[str[windowEnd]]++;
    while ((int)hm.size() > k) {
      hm[str[windowStart]]--;
      if (hm[str[windowStart]] <= 0) {
        hm.erase(str[windowStart]);
      }
      windowStart++;
    }
    maxLen = max(maxLen, windowEnd - windowStart + 1);
  }
  return maxLen;
}

int main() {
  string str;
  getline(cin, str);
  int k;
  cin >> k;
  cout << findLength(str, k);
  return 0;
}
