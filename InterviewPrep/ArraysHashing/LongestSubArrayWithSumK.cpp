#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
int lenOfLongestSubarr(vector<int>& arr, int k) {
  unordered_map<int, int> preMap;
  int maxLen = 0;
  int sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];

    if (sum == k) {
      maxLen = max(maxLen, i + 1);
    }

    int rem = sum - k;

    if (preMap.find(rem) != preMap.end()) {
      int len = i - preMap[rem];
      maxLen = max(maxLen, len);
    }

    if (preMap.find(sum) == preMap.end()) {
      preMap[sum] = i;
    }
  }
  return maxLen;
}

int main() {
  //   17 15
  vector<int> arr{-13, 0, 6,  15, 16, 2, 15, -12, 17,
                  -16, 0, -3, 19, -3, 2, -9, -6};
  cout << lenOfLongSubarr(arr, 17, 15);
  return 0;
}
