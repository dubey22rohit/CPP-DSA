#include <iostream>
#include <vector>
using namespace std;

// TC: O(n! * n)
// SC: O(1)
void permutationsHelper(vector<int>& nums, int start,
                        vector<vector<int>>& ans) {
  if (start == nums.size()) {
    ans.push_back(nums);
    return;
  }
  for (int i = start; i < nums.size(); i++) {
    swap(nums[i], nums[start]);
    permutationsHelper(nums, start + 1, ans);
    swap(nums[start], nums[i]);
  }
}

vector<vector<int>> permutations(vector<int>& nums) {
  vector<vector<int>> ans;
  permutationsHelper(nums, 0, ans);
  return ans;
}

int main() {
  vector<int> nums{1, 2, 3};
  vector<vector<int>> ans = permutations(nums);
  for (auto a : ans) {
    for (auto it : a) {
      cout << it << ", ";
    }
    cout << endl;
  }
  return 0;
}