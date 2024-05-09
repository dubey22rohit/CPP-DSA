#include <iostream>
using namespace std;

int climbStairsHelper(int n, vector<int> &dp) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int op = climbStairsHelper(n - 1, dp) + climbStairsHelper(n - 2, dp);
    dp[n] = op;
    return op;
}
int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return climbStairsHelper(n, dp);
}

int main() { return 0; }