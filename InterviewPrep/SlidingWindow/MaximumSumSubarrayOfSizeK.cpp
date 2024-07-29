#include <iostream>
#include <vector>
using namespace std;
// Maximum Sum Subarray of Size K (easy)
// Given an array of positive numbers and a positive number ‘k’, find the
// maximum sum of any contiguous subarray of size ‘k’.

/**
 * @brief Finds the maximum sum of any contiguous subarray of size 'k'.
 *
 * The function uses a sliding window approach to iterate through the array.
 * It maintains a window sum and a maximum sum. Initially, the window sum
 * is zero and the maximum sum is negative infinity. It then iterates through
 * the array, updating the window sum and the maximum sum. If the window
 * size is greater than or equal to 'k', it updates the maximum sum with
 * the current window sum and subtracts the element at the start of the window
 * from the window sum. It then moves the start of the window to the right.
 * The maximum sum is returned at the end.
 *
 * @param arr The array of positive numbers.
 * @param k The size of the subarray.
 * @return The maximum sum of any contiguous subarray of size 'k'.
 */
int findMaxSumSubArray(const vector<int>& arr, int k) {
  // Initialize variables to track the window sum and the maximum sum.
  int windowSum = 0, maxSum = INT_MIN;
  int windowStart = 0;

  // Iterate through the array.
  for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd) {
    // Update the window sum by adding the current element.
    windowSum += arr[windowEnd];

    // If the window size is greater than or equal to 'k', update the maximum
    // sum with the current window sum and subtract the element at the start
    // of the window from the window sum.
    if (windowEnd >= k) {
      maxSum = max(maxSum, windowSum);
      windowSum -= arr[windowStart];
      windowStart++;
    }
  }

  // Return the maximum sum.
  return maxSum;
}

int main() {
  vector<int> arr{2, 1, 5, 1, 3, 2};
  int maxSum = findMaxSumSubArray(arr, 2);
  cout << maxSum;
  return 0;
}