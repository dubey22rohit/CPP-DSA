#include <iostream>
#include <set>
#include <string>
using namespace std;

// No-repeat Substring (hard)
int findLength(const string &str) {
  set<char> visited;
  int maxLen = 0, windowStart = 0, windowEnd = 0;
  while (windowEnd < str.length()) {
    if (visited.find(str[windowEnd]) == visited.end()) {
      visited.insert(str[windowEnd]);
      windowEnd++;
      maxLen = max(maxLen, windowEnd - windowStart);
    } else {
      visited.erase(str[windowStart]);
      windowStart++;
    }
  }
  return maxLen;
}

// leetcode equivalent:
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
int lengthOfLongestSubstring(string s) {
  set<char> visited;
  int i = 0, j = 0;
  int maxLength = 0;
  while (j < s.length()) {
    if (visited.find(s[j]) == visited.end()) {
      visited.insert(s[j]);
      j++;
      maxLength = max(maxLength, j - i);
    } else {
      visited.erase(s[i]);
      i++;
    }
  }
  return maxLength;
}

int main() {
  string str;
  getline(cin, str);
  cout << findLength(str) << endl;
  cout << lengthOfLongestSubstring(str);
}
