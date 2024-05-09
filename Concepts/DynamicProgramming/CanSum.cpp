// Write a function canSum(targetSum, numbers)' that takes in a targetSum and an
// array of numbers as arguments. The function should return a boolean
// indicating whether or not it is possible to generate the targetSum using
// numbers from the array. You may use an element of the array as many times as
// needed. You may assume that all input numbers are nonnegative.

#include <iostream>
using namespace std;

// Without memoization:
//  m = target sum, height of tree
//  n = array length
//  TC: O(n ^ m)
//  SC: O(m): height of a tree at a given time

// With Memoization
//  TC: O(m * n)
//  SC: O(m): height of a tree at a given time

bool canSumR(int target, int *nums, int n, int *dp) {
    if (dp[target] != -1) {
        return dp[target];
    }
    if (target == 0) {
        return true;
    }
    if (target < 0) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        int rem = target - nums[i];
        bool smallAns = canSumR(rem, nums, n, dp);
        if (smallAns) {
            dp[target] = true;
            return true;
        }
    }
    dp[target] = false;
    return false;
}

int main() {
    int n, target;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cin >> target;

    int *dp = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i] = -1;
    }

    cout << (canSumR(target, input, n, dp) ? "can sum" : "can't sum");

    delete[] dp;

    return 0;
}