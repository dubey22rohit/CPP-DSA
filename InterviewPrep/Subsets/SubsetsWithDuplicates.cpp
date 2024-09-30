#include <iostream>
#include <vector>
using namespace std;

// TC and SC: O(2 ^ n)
vector<vector<int>> findSubsets(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> subsets;
  int startIndex = 0, endIndex = 0;
  subsets.push_back(vector<int>());
  for (int i = 0; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      startIndex = endIndex + 1;
    }
    endIndex = subsets.size() - 1;
    for (int j = startIndex; j <= endIndex; j++) {
      vector<int> set(subsets[j]);
      set.push_back(nums[i]);
      subsets.push_back(set);
    }
  }
  return subsets;
}

int main() {
  vector<int> nums{1, 5, 3, 3};
  vector<vector<int>> subsets = findSubsets(nums);
  for (vector<int> sub : subsets) {
    cout << "[";
    for (int s : sub) {
      cout << s << ",";
    }
    cout << "]";
  }
  return 0;
}