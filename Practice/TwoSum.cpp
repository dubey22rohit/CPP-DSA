#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//* https://leetcode.com/problems/two-sum/

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> hm;
  for (int i = 0; i < nums.size(); i++) {
    if (hm.find(target - nums[i]) != hm.end()) {
      return {i, hm[target - nums[i]]};
    }
    hm[nums[i]] = i;
  }

  return {};
}

int main() { return 0; }
