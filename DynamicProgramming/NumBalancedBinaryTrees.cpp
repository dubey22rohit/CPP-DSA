#include <cmath>
#include <iostream>
using namespace std;

int numBalancedBinaryTrees(int h, int *dp) {
    if (dp[h] > 0) {
        return dp[h];
    }

    if (h <= 1) {
        return 1;
    }

    int mod = (int)(pow(10, 9)) + 7;

    int x = numBalancedBinaryTrees(h - 1, dp);
    int y = numBalancedBinaryTrees(h - 2, dp);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);

    int ans = (temp1 + temp2) % mod;
    dp[h] = ans;
    return ans;
}

int main() {
    int h;
    cin >> h;
    int *dp = new int[h + 1];
    for (int i = 0; i < h + 1; i++) {
        dp[i] = 0;
    }
    cout << numBalancedBinaryTrees(h, dp);
    delete[] dp;
    return 0;
}