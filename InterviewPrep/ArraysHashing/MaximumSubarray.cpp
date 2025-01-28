#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/maximum-subarray/

int maxSubArray(vector<int>& nums) {
  int maxSum = nums[0], currSum = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    currSum += nums[i];
    currSum = max(currSum, nums[i]);
    maxSum = max(maxSum, currSum);
  }
  return maxSum;
}

// Kadane's Algorithm
int maxSubArrayKadane(vector<int>& nums) {
  int maxSum = INT_MIN;
  int currSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    currSum += nums[i];

    if (currSum > maxSum) {
      maxSum = currSum;
    }

    if (currSum < 0) {
      currSum = 0;
    }
  }

  return maxSum;
}

int main() { return 0; }