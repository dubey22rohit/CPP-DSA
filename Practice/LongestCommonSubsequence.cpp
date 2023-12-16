#include <iostream>
using namespace std;

int LongestCommonSubsequenceHelper(string s1, string s2, int **dp) {
  if (s1.length() == 0 || s2.length() == 0) {
    return 0;
  }

  if (dp[s1.length()][s2.length()] != -1) {
    return dp[s1.length()][s2.length()];
  }

  int lcs;
  if (s1[0] == s2[0]) {
    LongestCommonSubsequenceHelper(s1.substr(1), s2.substr(1), dp);
  } else {
    int a = LongestCommonSubsequenceHelper(s1.substr(1), s2, dp);
    int b = LongestCommonSubsequenceHelper(s1, s2.substr(1), dp);

    lcs = max(a, b);
  }

  dp[s1.length()][s2.length()] = lcs;
  return lcs;
}

int LongestCommonSubsequence(string s1, string s2) {
  int m = s1.length() + 1;
  int n = s2.length() + 1;

  int **dp = new int *[m];
  for (int i = 0; i < m; i++) {
    dp[i] = new int[n];
    for (int j = 0; j < n; j++) {
      dp[i][j] = -1;
    }
  }

  int lcs = LongestCommonSubsequenceHelper(s1, s2, dp);

  for (int i = 0; i < m; i++) {
    delete[] dp[i];
  }
  delete[] dp;

  return lcs;
}

int main() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);

  int ans = LongestCommonSubsequence(s1, s2);
  cout << ans;
}
