#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/generate-parentheses/
void generate(int n, string curr, int open, int close, vector<string>& ans) {
  if (open == n && close == n) {
    ans.push_back(curr);
    return;
  }
  if (open < n) {
    generate(n, curr + "(", open + 1, close, ans);
  }
  if (close < open) {
    generate(n, curr + ")", open, close + 1, ans);
  }
}
vector<string> generateParenthesis(int n) {
  vector<string> ans;
  generate(n, "", 0, 0, ans);
  return ans;
}

int main() {
  vector<string> op = generateParenthesis(3);
  for (auto s : op) {
    cout << s << ", ";
  }
  return 0;
}