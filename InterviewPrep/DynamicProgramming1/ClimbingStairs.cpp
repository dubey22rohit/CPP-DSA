#include <iostream>
#include <vector>
using namespace std;

int climbHelper(int n, vector<int> &dp) {
  if (n == 1 || n == 2) {
    return n;
  }
  if (dp[n] != -1) {
    return dp[n];
  }
  int ans = climbHelper(n - 1, dp) + climbHelper(n - 2, dp);
  dp[n] = ans;
  return ans;
}
int climbStairs(int n) {
  vector<int> dp(n + 1, -1);

  return climbHelper(n, dp);
}

int climbStairsDp(int n) {
  int first = 1, second = 1;
  for (int i = 0; i < n - 1; ++i) {
    int sum = first + second;
    second = first;
    first = sum;
  }

  return first;
}

int main() {
  int ans = climbStairs(10);
  int ans2 = climbStairsDp(10);
  cout << ans << endl;
  cout << ans2 << endl;
  return 0;
}