#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums) {
  int res = 0;
  for (int i = 0; i < nums.size(); i++) {
    res ^= nums[i];
  }
  return res;
}

int main() {
  vector<int> nums{4, 1, 2, 1, 2};
  cout << singleNumber(nums);
}
