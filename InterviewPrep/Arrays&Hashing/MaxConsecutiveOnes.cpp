#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
  int i = 0, j = 0, currMax = 0, allMax = 0;
  while (j < nums.size()) {
    while (j < nums.size() && nums[j] == 1) {
      currMax++;
      j++;
    }
    allMax = max(allMax, currMax);
    currMax = 0;

    i = j;
    j++;
  }
  return allMax;
}

int findMaxConsecutiveOnesOp(vector<int>& nums) {
  int maxi = INT_MIN, cnt = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 1) {
      cnt++;
    } else {
      maxi = max(maxi, cnt);
      cnt = 0;
    }
  }
  return maxi > cnt ? maxi : cnt;
}

int main() {
  vector<int> nums{1, 1, 0, 1, 1, 1, 1};
  cout << findMaxConsecutiveOnes(nums) << endl;
  cout << findMaxConsecutiveOnesOp(nums) << endl;
  return 0;
}