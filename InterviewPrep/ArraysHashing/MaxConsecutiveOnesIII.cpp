#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/max-consecutive-ones-iii/
int longestOnes(vector<int>& nums, int k) {
  int flips = k;
  int ws = 0;
  int maxLen = 0;
  for (int we = 0; we < nums.size(); we++) {
    if (nums[we] == 0) {
      flips--;
    }
    while (flips < 0) {
      if (nums[ws] == 0) {
        flips++;
      }
      ws++;
    }
    maxLen = max(maxLen, we - ws + 1);
  }
  return maxLen;
}

int main() { return 0; }