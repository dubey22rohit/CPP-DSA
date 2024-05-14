#include <iostream>
#include <vector>
using namespace std;

/*
To efficiently find the minimum element in a rotated sorted array, you can use
a modified binary search approach. The idea is to compare the middle element
of the array with the rightmost element to determine which half of the array is
sorted. If the middle element is greater than the rightmost element, it means
the right half is not sorted and the minimum element is on the right side. If
the middle element is less than the rightmost element, it means the right half
is sorted, and the minimum element is on the left side. You continue this
process until you find the minimum element.
*/
// min = start of an un-rotated array, so always search in the rotated half

int findMin(vector<int>& nums) {
  int left = 0, right = nums.size() - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[right]) {
      left = mid + 1;
    } else if (nums[mid] < nums[right]) {
      right = mid;
    }
  }
  return nums[left];
}

int main() {
  vector<int> nums{4, 5, 1, 2, 3};
  cout << findMin(nums);
  return 0;
}