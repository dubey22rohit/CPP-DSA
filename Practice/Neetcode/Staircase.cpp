#include <iostream>
using namespace std;

int staircase(int n, int dp[]) {
    if (dp[n]) {
        return dp[n];
    }
    if (n < 0) {
        return 0;
    }

    if (n == 0) {
        return 1;
    }
    int ans =
        staircase(n - 1, dp) + staircase(n - 2, dp) + staircase(n - 3, dp);
    dp[n] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;

    int *dp = new int[n + 1];

    int ans = staircase(n, dp);
    cout << ans;

    return 0;
}