#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/single-element-in-a-sorted-array/

// O(N) solution
int singleNonDuplicateXOR(vector<int>& nums) {
  int ans = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    ans ^= nums[i];
  }
  return ans;
}

// O(logn) solution:
// https://takeuforward.org/data-structure/search-single-element-in-a-sorted-array/
// TODO: Revise
int singleNonDuplicate(vector<int>& nums) {
  int n = nums.size();
  if (n == 1) {
    return nums[0];
  }

  if (nums[0] != nums[1]) {
    return nums[0];
  }
  if (nums[n - 1] != nums[n - 2]) {
    return nums[n - 1];
  }

  int s = 1, e = n - 2;
  while (s <= e) {
    int m = s + (e - s) / 2;
    if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1]) {
      return nums[m];
    }
    if ((m % 2 == 0 && nums[m] == nums[m + 1]) ||
        (m % 2 == 1 && nums[m] == nums[m - 1])) {
      s = m + 1;
    } else {
      e = m - 1;
    }
  }
  return -1;
}
int main() { return 0; }