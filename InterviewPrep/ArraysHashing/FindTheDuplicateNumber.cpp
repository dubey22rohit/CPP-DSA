#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/description/

int findDuplicate(vector<int>& nums) {
  int slow = nums[0];
  int fast = nums[0];

  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);

  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}

int main() { return 0; }