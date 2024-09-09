#include <iostream>
#include <vector>
using namespace std;

void combinationSumHelper(vector<int>& candidates, int target,
                          vector<int>& curr, vector<vector<int>>& ans,
                          int idx) {
  if (idx == candidates.size()) {
    if (target <= 0) {
      ans.push_back(curr);
    }
    return;
  }

  if (target >= candidates[idx]) {
    // We pick an element and don't increment the index as it can be picked
    // again.
    curr.push_back(candidates[idx]);
    combinationSumHelper(candidates, target - candidates[idx], curr, ans, idx);
    // We must remove the picked element from the curr before moving forward.
    curr.pop_back();
  }
  combinationSumHelper(candidates, target, curr, ans, idx + 1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> ans;
  vector<int> curr;
  combinationSumHelper(candidates, target, curr, ans, 0);
  return ans;
}

int main() {
  vector<int> nums{1, 2, 3, 4, 5};
  vector<vector<int>> cs = combinationSum(nums, 5);
  for (auto c : cs) {
    for (auto a : c) {
      cout << a << " ";
    }
    cout << endl;
  }
  return 0;
}