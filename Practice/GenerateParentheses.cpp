#include <iostream>
#include <vector>
using namespace std;

void generate(int n, int open, int close, string curr, vector<string> &ans) {
  if (open == n && close == n) {
    ans.push_back(curr);
    return;
  }
  if (open < n) {
    generate(n, open + 1, close, curr + "(", ans);
  }
  if (close < open) {
    generate(n, open, close + 1, curr + ")", ans);
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> ans;
  generate(n, 0, 0, "", ans);
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<string> ans = generateParenthesis(n);
  for (auto c : ans) {
    cout << c << " ";
  }
  return 0;
}
