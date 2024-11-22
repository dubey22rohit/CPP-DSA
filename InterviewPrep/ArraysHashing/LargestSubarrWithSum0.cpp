#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
int maxLen(vector<int>& arr, int n) {
  int sum = 0;
  unordered_map<int, int> hm;
  int maxLen = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum == 0) {
      maxLen = max(maxLen, i + 1);
    } else {
      if (hm.find(sum) != hm.end()) {
        maxLen = max(maxLen, i - hm[sum]);
      } else {
        hm[sum] = i;
      }
    }
  }
  return maxLen;
}

int main() { return 0; }