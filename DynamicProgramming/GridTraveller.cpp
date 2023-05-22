// Say that you are a traveler on a 2D grid. You begin in the top-left corner
// and your goal is to travel to the bottom-right corner.
// You may only move down or right.
// In how many ways can you travel to the goal on a grid with dimensions m * n?

#include <iostream>
#define lli long long int
using namespace std;

// TC: O(m * n)
// SC: O(m + n)
int gridTravelerMemo(int m, int n, lli **dp) {
    if (dp[m][n] != -1) {
        return dp[m][n];
    }

    if (m == 1 && n == 1) {
        return 1;
    }
    if (m == 0 || n == 0) {
        return 0;
    }

    dp[m][n] = gridTravelerMemo(m - 1, n, dp) + gridTravelerMemo(m, n - 1, dp);
    return dp[m][n];
}

// TC: O(2 ^ (m+n))
// SC: O(m + n)
int gridTraveler(int m, int n) {
    if (m == 1 && n == 1) {
        return 1;
    }
    if (m == 0 || n == 0) {
        return 0;
    }

    return gridTraveler(m - 1, n) + gridTraveler(m, n - 1);
}

int main() {
    int m, n;
    cin >> m >> n;

    lli **dp = new lli *[m + 1];
    for (int i = 0; i < m + 1; i++) {
        dp[i] = new lli[n + 1];
        for (int j = 0; j < n + 1; j++) {
            dp[i][j] = -1;
        }
    }

    int ansMemo = gridTravelerMemo(m, n, dp);
    cout << "Total ways to move: " << ansMemo;

    for (int i = 0; i < m; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return 0;
}