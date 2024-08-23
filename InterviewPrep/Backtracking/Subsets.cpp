#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& nums, int start, vector<int>& curr,
         vector<vector<int>>& res) {
  res.push_back(curr);
  for (int i = start; i < nums.size(); ++i) {
    curr.push_back(nums[i]);
    dfs(nums, i + 1, curr, res);
    curr.pop_back();
  }
}

vector<vector<int>> arraySubsets(vector<int>& nums) {
  vector<int> curr;
  vector<vector<int>> res;
  dfs(nums, 0, curr, res);
  return res;
}

int main() {
  vector<int> nums{1, 2, 3};
  vector<vector<int>> ans = arraySubsets(nums);

  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < ans[i].size(); ++j) {
      cout << ans[i][j] << ", ";
    }
    cout << endl;
  }
  return 0;
}