// Write a function "howSum(targetSum, numbers) that takes in a targetSum and an
// array of numbers as arguments. The function should return an array containing
// any combination of elements that add up to exactly the targetSum. If there is
// no combination that adds up to the targetSum, then return null. If there are
// multiple combinations possible, you may return any single one.

#include <iostream>
#include <vector>
using namespace std;

vector<int> howSum(int target, vector<int> &nums) {
    if (target == 0) {
        return {};
    }
    if (target < 0) {
        return {-1};
    }

    for (int i = 0; i < nums.size(); i++) {
        int rem = target - nums[i];
        vector<int> smallAns = howSum(rem, nums);
        if (smallAns[0] != -1) {
            for (int i = 0; i < smallAns.size(); i++) {
                nums.push_back(smallAns[i]);
            }
            nums.push_back(nums[i]);
        }
    }
    return {-1};
}

int main() {
    int n, target;
    cin >> n;
    vector<int> input;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        input.push_back(a);
    }

    int *dp = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i] = -1;
    }

    cin >> target;

    vector<int> ans = howSum(target, input);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    delete[] dp;

    return 0;
}