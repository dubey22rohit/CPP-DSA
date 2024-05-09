#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    for (int i = 2; i < n; i++) {
        cost[i] += min(cost[i - 1], cost[i - 2]);
    }
    return min(cost[n - 1], cost[n - 2]);
}

int minCostClimbingStairsRHelper(vector<int>& cost, int i, vector<int>& dp) {
    if (i == 0 || i == 1) {
        return 0;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    int c1 = cost[i - 1] + minCostClimbingStairsRHelper(cost, i - 1, dp);
    int c2 = cost[i - 2] + minCostClimbingStairsRHelper(cost, i - 2, dp);

    int ans = min(c1, c2);
    dp[i] = ans;

    return ans;
}

int minCostClimbingStairsR(vector<int>& cost) {
    vector<int> dp(cost.size() + 1, -1);
    return minCostClimbingStairsRHelper(cost, cost.size(), dp);
}

int main() {
    int n;
    cin >> n;

    vector<int> input(n);

    for (int i = 0, a; i < n; i++) {
        cin >> a;
        input.push_back(a);
    }

    int ans = minCostClimbingStairs(input);
    cout << ans;

    return 0;
}