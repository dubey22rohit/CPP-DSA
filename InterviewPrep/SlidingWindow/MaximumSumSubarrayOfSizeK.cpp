#include <iostream>
#include <vector>
using namespace std;
// Maximum Sum Subarray of Size K (easy)
// Given an array of positive numbers and a positive number ‘k’, find the
// maximum sum of any contiguous subarray of size ‘k’.

static int findMaxSumSubArray(const vector<int>& arr, int k) {
  int windowSum = 0, maxSum = 0;
  int windowStart = 0;
  for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd) {
    windowSum += arr[windowEnd];
    if (windowEnd >= k) {
      maxSum = max(maxSum, windowSum);
      windowSum -= arr[windowStart];
      windowStart++;
    }
  }
  return maxSum;
}

int main() {
  vector<int> arr{2, 1, 5, 1, 3, 2};
  int maxSum = findMaxSumSubArray(arr, 2);
  cout << maxSum;
  return 0;
}