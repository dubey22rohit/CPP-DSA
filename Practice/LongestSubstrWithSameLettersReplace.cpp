#include <iostream>
#include <unordered_map>
using namespace std;

// Longest Substring with Same Letters after Replacement (hard)
int findLength(const string &str, int k) {
  int maxLen = 0, windowStart = 0, maxRepeatLeterCount = 0;
  unordered_map<char, int> hm;
  for (int windowEnd = 0; windowEnd < str.length(); ++windowEnd) {
    hm[str[windowEnd]]++;
    maxRepeatLeterCount = max(maxRepeatLeterCount, hm[str[windowEnd]]);
    if (windowEnd - windowStart + 1 - maxRepeatLeterCount > k) {
      hm[str[windowStart]]--;
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
  cout << findLength(str, k) << endl;
}
