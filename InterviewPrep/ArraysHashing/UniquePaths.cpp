#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/unique-paths/
// Revise
int uniquePaths(int m, int n, int i, int j, vector<vector<int>>& dp) {
  if (i == m - 1 && j == n - 1) {
    return 1;
  }
  if (i >= m || j >= n) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  dp[i][j] = uniquePaths(m, n, i + 1, j, dp) + uniquePaths(m, n, i, j + 1, dp);
  return dp[i][j];
}
int uniquePaths(int m, int n) {
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  int ans = uniquePaths(m, n, 0, 0, dp);
  if (m == 1 && n == 1) {
    return ans;
  }
  return dp[0][0];
}

int uniquePathsOp(int m, int n) {
  int N = n + m - 2;
  int r = m - 1;
  double res = 1;

  for (int i = 1; i <= r; i++) res = res * (N - r + i) / i;
  return (int)res;
}

int main() { return 0; }