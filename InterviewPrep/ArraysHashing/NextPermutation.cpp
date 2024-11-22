#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/next-permutation/

// TC: O(3N) == O(N)
void nextPermutation(vector<int>& nums) {
  int idx = -1;
  int n = nums.size();

  for (int i = n - 2; i >= 0; i--) {
    if (nums[i] < nums[i + 1]) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    reverse(nums.begin(), nums.end());
  }

  for (int i = n - 1; i >= idx; i--) {
    if (nums[i] > nums[idx]) {
      swap(nums[i], nums[idx]);
      break;
    }
  }

  reverse(nums.begin() + idx + 1, nums.end());
}

int main() {
  vector<int> nums{1, 2, 3};
  nextPermutation(nums);
  for (int n : nums) {
    cout << n << ", ";
  }
  return 0;
}