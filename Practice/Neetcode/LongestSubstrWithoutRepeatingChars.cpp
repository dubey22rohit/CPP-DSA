#include <iostream>
#include <set>
using namespace std;

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
  string s;
  getline(cin, s);

  int maxLen = lengthOfLongestSubstring(s);
  cout << maxLen;

  return 0;
}
