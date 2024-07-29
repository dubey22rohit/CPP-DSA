#include <iostream>
#include <vector>
using namespace std;

// Given an array of sorted numbers and a target sum,
// find a pair in the array whose sum is equal to the given target

// Write a function to return the indices of the two
// numbers(i.e.the pair) such that they add up to the given target.

// Similar to Two Sum from leetcode

/**
 * @brief Finds a pair of indices in a sorted array whose elements sum up to a
 * target value.
 *
 * @param arr The sorted array of integers.
 * @param targetSum The target sum.
 *
 * @return A pair of indices (i, j) such that arr[i] + arr[j] = targetSum, or
 * (-1, -1) if no such pair exists.
 *
 * @throws None
 */
pair<int, int> search(const vector<int> &arr, int targetSum) {
  // Initialize pointers to the start and end of the array.
  int left = 0, right = arr.size() - 1;

  // Iterate until the pointers meet or pass each other.
  while (left < right) {
    // If the sum of the current pair is less than the target, move the left
    // pointer to the right to increase the sum.
    if (arr[left] + arr[right] < targetSum) {
      left++;
    }
    // If the sum of the current pair is greater than the target, move the right
    // pointer to the left to decrease the sum.
    else if (arr[left] + arr[right] > targetSum) {
      right--;
    }
    // If the sum is equal to the target, return the indices.
    else {
      return make_pair(left, right);
    }
  }

  // If no pair with the target sum is found, return (-1, -1).
  return make_pair(-1, -1);
}
// The time complexity of the above algorithm will be 𝑂(𝑁)
// O(N), where ‘N’ is the total number of elements in the given array.
// The algorithm runs in constant space O(1)

int main() {
  vector<int> arr{2, 5, 9, 11};
  pair<int, int> ans = search(arr, 11);
  cout << ans.first << " " << ans.second << "\n";
  return 0;
}