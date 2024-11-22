#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
  int l = 0, r = nums.size() - 1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (nums[mid] < target) {
      l = mid + 1;
    } else if (nums[mid] > target) {
      r = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  vector<int> nums{-1, 0, 3, 5, 9, 12};
  cout << search(nums, 9);
  return 0;
}