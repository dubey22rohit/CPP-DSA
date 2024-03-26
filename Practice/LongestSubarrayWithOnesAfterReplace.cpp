#include <iostream>
using namespace std;

// Longest Subarray with Ones after Replacement(hard)
int findLength(const vector<int> &arr, int k) {
  int maxLength = 0, windowStart = 0, maxOnesCount = 0;
  for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd) {
    if (arr[windowEnd] == 1) {
      maxOnesCount++;
    }
    if (windowEnd - windowStart + 1 - maxOnesCount > k) {
      if (arr[windowStart] == 1) {
        maxOnesCount--;
      }
      windowStart++;
    }
    maxLength = max(maxLength, windowEnd - windowStart + 1);
  }
  return maxLength;
}

int main() {
  vector<int> arr{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1};
  cout << findLength(arr, 2) << endl;
}
