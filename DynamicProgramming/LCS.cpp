#include <iostream>
using namespace std;

// TC:Exponential O(2^n) : Without memoization
int LCS(string s1, string s2, int **dp) {
    if (s1.length() == 0 || s2.length() == 0) {
        return 0;
    }

    if (dp[s1.length()][s2.length()] != -1) {
        return dp[s1.length()][s2.length()];
    }

    int ans;
    if (s1[0] == s2[0]) {
        ans = LCS(s1.substr(1), s2.substr(1), dp) + 1;
    } else {
        int a = LCS(s1.substr(1), s2, dp);
        int b = LCS(s1, s2.substr(1), dp);
        // int c = LCS(s1.substr(1), s2.substr(1));This call will be handeled
        // automatically
        ans = max(a, b);
    }
    dp[s1.length()][s2.length()] = ans;
    return ans;
}

int LCS(string s1, string s2) {
    int m = s1.length() + 1;
    int n = s2.length() + 1;

    int **dp = new int *[m];
    for (int i = 0; i < m; i++) {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    int ans = LCS(s1, s2, dp);
    for (int i = 0; i < m; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

int main() {
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    cout << LCS(s1, s2);
    return 0;
}