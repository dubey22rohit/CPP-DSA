#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/missing-number/description/
int missingNumber(vector<int>& nums) {
  int n = nums.size();
  int sum = ((n) * (n + 1)) / 2;
  for (int num : nums) {
    sum -= num;
  }
  return sum;
}
int main() {
  vector<int> nums{0, 1, 2, 3, 4, 5, 6, 7, 9};
  cout << missingNumber(nums);
  return 0;
}