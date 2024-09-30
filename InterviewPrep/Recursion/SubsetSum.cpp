#include <iostream>
#include <vector>
using namespace std;

void subsetSumHelper(vector<int> &nums, vector<int> &dp, int sum, int idx) {
  if (idx >= nums.size()) {
    dp.push_back(sum);
    return;
  }
  // Adding the nums[idx] to sum once, next time not;
  // could be done like this as well:
  // sum += nums[idx];
  // subsetSumHelper(nums, dp, sum, idx + 1);
  // sum -= nums[idx];
  // subsetSumHelper(nums, dp, sum, idx + 1);
  subsetSumHelper(nums, dp, sum + nums[idx], idx + 1);
  subsetSumHelper(nums, dp, sum, idx + 1);
}

vector<int> subsetSum(vector<int> &nums) {
  vector<int> dp;
  subsetSumHelper(nums, dp, 0, 0);
  sort(dp.begin(), dp.end());
  return dp;
}

int main() {
  vector<int> nums{2, 3};
  vector<int> ans = subsetSum(nums);
  for (auto a : ans) {
    cout << a << " ";
  }
  return 0;
}