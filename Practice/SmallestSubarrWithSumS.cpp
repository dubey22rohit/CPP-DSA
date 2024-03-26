#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// Smallest Subarray with a given sum (easy)
// TC: O(N + N) == O(N)
// The outer for loop runs for all elements and the inner while loop processes
// each element only once.
int findMinSubArray(int S, const vector<int> &arr) {
  int minLen = INT_MAX;
  int windowStart = 0;
  int windowSum = 0;
  for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
    windowSum += arr[windowEnd];
    while (windowSum >= S) {
      minLen = min(minLen, windowEnd - windowStart + 1);
      windowSum -= arr[windowStart];
      windowStart++;
    }
  }
  return minLen == INT_MAX ? 0 : minLen;
}

int main() {
  vector<int> arr{2, 1, 5, 2, 8};
  int ans = findMinSubArray(7, arr);
  cout << ans;
  return 0;
}
