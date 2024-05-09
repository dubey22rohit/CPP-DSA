#include <iostream>
using namespace std;

// TC: O(m * n)
// SC: O(m * n)
int minCostPath_DP(int **input, int m, int n) {
    int **output = new int *[m];
    for (int i = 0; i < m; i++) {
        output[i] = new int[n];
    }

    output[m - 1][n - 1] = input[m - 1][n - 1];
    for (int j = n - 2; j >= 0; j--) {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    for (int i = m - 2; i >= 0; i--) {
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
    }

    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            output[i][j] = min(output[i][j + 1],
                               min(output[i + 1][j + 1], output[i + 1][j])) +
                           input[i][j];
        }
    }
    return output[0][0];
}

// TC: O(m * n)
// SC: O(m * n)
int minCostPath(int **input, int m, int n, int i, int j, int **dp) {
    if ((i == m - 1) && (j == n - 1)) {
        return input[i][j];
    }

    if (i >= m || j >= n) {
        return INT_MAX;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int x = minCostPath(input, m, n, i, j + 1, dp);
    int y = minCostPath(input, m, n, i + 1, j + 1, dp);
    int z = minCostPath(input, m, n, i + 1, j, dp);

    // Small calculation
    int ans = min(x, min(y, z)) + input[i][j];
    dp[i][j] = ans;
    return ans;
}

int minCostPath(int **input, int m, int n) {
    int **dp = new int *[m];
    for (int i = 0; i < m; i++) {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    int ans = minCostPath(input, m, n, 0, 0, dp);
    for (int i = 0; i < m; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;
    int **input = new int *[m];
    for (int i = 0; i < m; i++) {
        input[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    cout << minCostPath(input, m, n) << endl;
    cout << minCostPath_DP(input, m, n) << endl;
    return 0;
}