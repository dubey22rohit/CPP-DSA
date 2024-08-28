#include <iostream>
#include <vector>
using namespace std;

int fibR(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  return fibR(n - 1) + fibR(n - 2);
}

int fibTabulation(int n) {
  vector<int> dp(n + 1, -1);

  if (n == 0 || n == 1) {
    return n;
  }

  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int main() {
  cout << fibR(10) << endl;
  cout << fibTabulation(10) << endl;
  return 0;
}