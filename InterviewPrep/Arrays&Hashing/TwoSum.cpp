#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> hm;
  for (int i = 0; i < nums.size(); ++i) {
    if (hm.find(target - nums[i]) != hm.end()) {
      return {i, hm[target - nums[i]]};
    } else {
      hm[nums[i]] = i;
    }
  }
  return {};
}

int main() {
  vector<int> nums = {2, 7, 11, 15};
  vector<int> ans = twoSum(nums, 9);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}