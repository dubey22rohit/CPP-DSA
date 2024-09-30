#include <iostream>
#include <vector>
using namespace std;

void subsetHelper(vector<int> &nums, vector<int> &dp, vector<vector<int>> &ans,
                  int idx) {
  ans.push_back(dp);
  for (int i = idx; i < nums.size(); i++) {
    if (i != idx && nums[i] == nums[i - 1]) {
      continue;
    }
    dp.push_back(nums[i]);
    subsetHelper(nums, dp, ans, i + 1);
    dp.pop_back();
  }
}

vector<vector<int>> subsets(vector<int> &nums) {
  vector<int> dp;
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  subsetHelper(nums, dp, ans, 0);
  return ans;
}

int main() {
  vector<int> nums{1, 2, 2};
  vector<vector<int>> ans = subsets(nums);
  for (auto a : ans) {
    for (auto it : a) {
      cout << it << ", ";
    }
    cout << endl;
  }
  return 0;
}