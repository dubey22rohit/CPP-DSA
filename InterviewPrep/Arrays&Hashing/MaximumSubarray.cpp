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

int main() { return 0; }