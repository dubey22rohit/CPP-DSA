#include <iostream>
#include <vector>
using namespace std;

int lenOfLongSubarr(vector<int> &arr, int n, int k) {
  int ws = 0, len = 0;
  long long currSum = 0;
  for (int we = 0; we < n; ++we) {
    currSum += arr[we];
    while (currSum > k) {
      currSum -= arr[ws];
      ws++;
    }
    if (currSum == k) {
      len = max(len, we - ws + 1);
    }
  }
  return len;
}

int main() {
  //   17 15
  vector<int> arr{-13, 0, 6,  15, 16, 2, 15, -12, 17,
                  -16, 0, -3, 19, -3, 2, -9, -6};
  cout << lenOfLongSubarr(arr, 17, 15);
  return 0;
}
