#include <iostream>
#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
  int ws = 0, currSum = 0, ans = 0;
  for (int we = 0; we < nums.size(); ++we) {
    currSum += nums[we];
    while (currSum >= k && ws < nums.size()) {
      if (currSum == k) {
        ans++;
      }
      currSum -= nums[ws];
      ws++;
    }
  }
  return ans;
}

int main() {
  vector<int> nums{1};
  cout << subarraySum(nums, 0);
  return 0;
}