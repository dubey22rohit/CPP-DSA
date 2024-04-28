#include <iostream>
#include <vector>
using namespace std;

// Maximum Sum Subarray of Size K (easy)
// TC: O(N)
int findMaximumSubarray(int k, const vector<int> &arr) {
  int maxSum = 0;
  int windowStart = 0;
  int windowSum = 0;
  for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd) {
    windowSum += arr[windowEnd];
    if (windowEnd >= k - 1) {
      maxSum = max(maxSum, windowSum);
      windowSum -= arr[windowStart];
      windowStart++;
    }
  }
  return maxSum;
}

int main() {
  vector<int> arr{2, 3, 4, 1, 5};
  int maxSum = findMaximumSubarray(2, arr);
  cout << maxSum;
}
