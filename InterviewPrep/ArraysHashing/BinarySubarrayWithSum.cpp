#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/binary-subarrays-with-sum/

// This method gets the number of subarrays with sum  <= to goal.
int getGoals(vector<int>& nums, int goal) {
  if (goal < 0) {
    return 0;
  }
  int ws = 0, we = 0;
  int currSum = 0;
  int totalGoals = 0;
  while (we < nums.size()) {
    currSum += nums[we];
    while (currSum > goal && ws <= we) {
      currSum -= nums[ws];
      ws++;
    }
    totalGoals += we - ws + 1;
    we++;
  }
  return totalGoals;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
  // (num of sums <= goal) - (num of sums <= goal - 1) = num of goals
  return getGoals(nums, goal) - getGoals(nums, goal - 1);
}

int main() {
  vector<int> nums{1, 0, 1, 0, 1};
  cout << numSubarraysWithSum(nums, 2);
  return 0;
}