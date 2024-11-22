#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
  int ans = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    ans ^= nums[i];
  }
  return ans;
}
int main() {
  vector<int> nums{1, 1, 2, 4, 4};
  cout << singleNumber(nums);
  return 0;
}