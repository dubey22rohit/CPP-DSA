#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

void dfs(string digits, string mapping[], vector<string>& result,
         string currStr, int idx) {
  if (idx >= digits.size()) {
    result.push_back(currStr);
    return;
  }

  int digit = digits[idx] - '0';
  string val = mapping[digit];

  for (int i = 0; i < val.size(); i++) {
    currStr.push_back(val[i]);
    dfs(digits, mapping, result, currStr, idx + 1);
    currStr.pop_back();
  }
}

vector<string> letterCombinations(string digits) {
  vector<string> result;
  if (digits.size() == 0) {
    return result;
  }
  string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
  dfs(digits, mapping, result, "", 0);
  return result;
}

int main() {
  vector<string> result = letterCombinations("23");
  for (auto s : result) {
    cout << s << ", ";
  }
  return 0;
}