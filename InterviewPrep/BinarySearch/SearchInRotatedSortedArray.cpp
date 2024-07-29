#include <iostream>
#include <vector>
using namespace std;

/**
 * Searches for a target number in a rotated sorted array.
 *
 * @param nums The rotated sorted array.
 * @param target The target number to search for.
 * @return The index of the target number if found, -1 otherwise.
 */
int search(vector<int>& nums, int target) {
  // Initialize left and right indices.
  int left = 0, right = nums.size() - 1;

  // Perform binary search.
  while (left <= right) {
    int mid = left + (right - left) / 2;

    // If target is found, return the index.
    if (nums[mid] == target) {
      return mid;
    }

    // If the left half is sorted, search in that half.
    if (nums[left] <= nums[mid]) {
      // If target is in the left half, search in the right half.
      if (nums[left] <= target && target <= nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else {
      // If target is in the right half, search in the left half.
      if (nums[mid] <= target && target <= nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }

  // Target not found.
  return -1;
}

int main() {
  vector<int> nums{4, 5, 6, 7, 0, 1, 2};
  cout << search(nums, 0);
  return 0;
}
