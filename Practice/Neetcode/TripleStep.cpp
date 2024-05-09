#include <iostream>
using namespace std;

int numSteps(int n, int dp[]) {
    if (dp[n]) {
        return dp[n];
    }
    if (n < 0) {
        return 0;
    }

    if (n == 0) {
        return 1;
    }

    int ans = numSteps(n - 1, dp) + numSteps(n - 2, dp) + numSteps(n - 3, dp);
    dp[n] = ans;

    return ans;
}

int main() {
    int n;
    cin >> n;

    int *dp = new int[n + 1]();
    cout << numSteps(n, dp);
    return 0;
}