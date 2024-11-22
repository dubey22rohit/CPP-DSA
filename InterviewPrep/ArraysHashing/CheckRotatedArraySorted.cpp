#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
bool check(vector<int>& nums) {
  int cnt = 0;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i - 1] > nums[i]) {
      cnt++;
    }
  }
  if (nums[nums.size() - 1] > nums[0]) {
    cnt++;
  }

  return cnt <= 1;
}

int main() {
  vector<int> nums{3, 4, 5, 1, 2};
  cout << check(nums);
  return 0;
}