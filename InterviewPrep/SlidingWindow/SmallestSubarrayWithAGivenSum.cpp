#include <iostream>
#include <vector>
using namespace std;

// Smallest Subarray with a given sum (easy)
// Given an array of positive numbers and a positive number ‘S’, find the length
// of the smallest contiguous subarray whose sum is greater than or equal to
// ‘S’. Return 0, if no such subarray exists.

static int findMinSubArray(const vector<int>& arr, int S) {
  int windowSum = 0;
  int windowStart = 0;
  int minLength = INT_MAX;
  for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd) {
    windowSum += arr[windowEnd];
    while (windowSum >= S) {
      minLength = min(minLength, windowEnd - windowStart + 1);
      windowSum -= arr[windowStart];
      windowStart++;
    }
  }
  return minLength == INT_MAX ? 0 : minLength;
}

int main() {
  vector<int> arr{2, 1, 5, 2, 3, 2};
  int minLength = findMinSubArray(arr, 7);
  cout << minLength;
  return 0;
}