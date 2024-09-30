#include <iostream>
#include <vector>
using namespace std;

// time complexity: O(2^n)
// space complexity: O(2^n)
vector<vector<int>> findSubsets(vector<int> &nums) {
  vector<vector<int>> subsets;
  subsets.push_back(vector<int>());
  for (auto num : nums) {
    int n = subsets.size();
    for (int i = 0; i < n; i++) {
      vector<int> set(subsets[i]);
      set.push_back(num);
      subsets.push_back(set);
    }
  }
  return subsets;
}

int main() {
  vector<int> nums{1, 2, 3};
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
