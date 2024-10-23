#include <iostream>
#include <vector>
using namespace std;

// TODO: Fix
int maxLen(vector<int>& arr, int n) {
  int ws = 0, maxLen = 0, currSum = 0;
  for (int we = 0; we < n; we++) {
    currSum += arr[we];
    while (currSum >= 0) {
      maxLen = max(maxLen, we - ws + 1);
      currSum -= arr[ws];
      ws++;
    }
  }
  return maxLen;
}

int main() {
  vector<int> arr{15, -2, 2, -8, 1, 7, 10, 23};
  cout << maxLen(arr, 8);
  return 0;
}