#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--]) {
        return false;
      }
    }
    return true;
  }
  void dfs(string s, vector<string>& curr, int idx,
           vector<vector<string>>& result) {
    if (idx == s.size()) {
      result.push_back(curr);
      return;
    }
    for (int i = idx; i < s.size(); i++) {
      if (isPalindrome(s, idx, i)) {
        curr.push_back(s.substr(idx, i - idx + 1));
        dfs(s, curr, i + 1, result);
        curr.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> curr;
    dfs(s, curr, 0, result);
    return result;
  }
};

int main() { return 0; }