#include <iostream>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
int lengthOfLongestSubstring(string s) {
  unordered_map<char, int> hm;
  int ws = 0, maxLen = 0;
  for (int we = 0; we < s.size(); we++) {
    hm[s[we]]++;
    while (hm[s[we]] > 1) {
      hm[s[ws]]--;
      if (hm[s[ws]] <= 0) {
        hm.erase(s[ws]);
      }
      ws++;
    }
    maxLen = max(maxLen, we - ws + 1);
  }
  return maxLen;
}

int main() { return 0; }