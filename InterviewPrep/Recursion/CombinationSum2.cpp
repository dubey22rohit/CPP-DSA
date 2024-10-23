#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/combination-sum-ii/
void combinationSumHelper(vector<int>& candidates, int target,
                          vector<int>& curr, vector<vector<int>>& ans,
                          int idx) {
  if (target == 0) {
    ans.push_back(curr);
    return;
  }

  for (int i = idx; i < candidates.size(); i++) {
    if (i > idx && candidates[i] == candidates[i - 1]) {
      continue;
    }
    if (candidates[i] > target) {
      break;
    }
    curr.push_back(candidates[i]);
    combinationSumHelper(candidates, target - candidates[i], curr, ans, i + 1);
    curr.pop_back();
  }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector<vector<int>> ans;
  vector<int> curr;
  combinationSumHelper(candidates, target, curr, ans, 0);
  return ans;
}

int main() {
  vector<int> nums{10, 1, 2, 7, 6, 1, 5};
  vector<vector<int>> cs = combinationSum(nums, 8);
  for (auto c : cs) {
    for (auto a : c) {
      cout << a << " ";
    }
    cout << endl;
  }
  return 0;
}