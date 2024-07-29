#include <iostream>
#include <vector>
using namespace std;

// Smallest Subarray with a given sum (easy)
// Given an array of positive numbers and a positive number ‘S’, find the length
// of the smallest contiguous subarray whose sum is greater than or equal to
// ‘S’. Return 0, if no such subarray exists.

/**
 * @brief Finds the length of the smallest contiguous subarray whose sum is
 * greater than or equal to the given target sum.
 *
 * @param arr The array of positive numbers.
 * @param S The target sum.
 *
 * @return The length of the smallest contiguous subarray or 0 if no such
 * subarray exists.
 */
int findMinSubArray(const vector<int>& arr, int S) {
  // Initialize variables to track the sum of the current window and the
  // start and end indices of the window.
  int windowSum = 0;
  int windowStart = 0;
  int minLength = INT_MAX;

  // Iterate through the array.
  for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd) {
    // Add the current element to the window sum.
    windowSum += arr[windowEnd];

    // While the window sum is greater than or equal to the target sum,
    // update the minimum length if necessary and shrink the window.
    while (windowSum >= S) {
      minLength = min(minLength, windowEnd - windowStart + 1);
      windowSum -= arr[windowStart];
      windowStart++;
    }
  }

  // Return the minimum length or 0 if no subarray exists.
  return minLength == INT_MAX ? 0 : minLength;
}

int main() {
  vector<int> arr{2, 1, 5, 2, 3, 2};
  int minLength = findMinSubArray(arr, 7);
  cout << minLength;
  return 0;
}