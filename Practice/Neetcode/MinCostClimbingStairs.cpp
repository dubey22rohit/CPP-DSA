#include <iostream>
using namespace std;

int minCostClimbingStairsHelper(vector<int>& cost, int i, vector<int>& dp) {
    if (i == 0 || i == 1) {
        return 0;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    int c1 = cost[i - 1] + minCostClimbingStairsHelper(cost, i - 1, dp);
    int c2 = cost[i - 2] + minCostClimbingStairsHelper(cost, i - 2, dp);

    int fc = min(c1, c2);
    dp[i] = fc;
    return fc;
}

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size() + 1, -1);
    return minCostClimbingStairsHelper(cost, cost.size(), dp);
}

int main() { return 0; }