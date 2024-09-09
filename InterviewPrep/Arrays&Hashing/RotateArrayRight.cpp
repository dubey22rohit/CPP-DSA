#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
  int n = nums.size();
  k %= n;
  reverse(nums.begin(), nums.begin() + (n - k));
  reverse(nums.begin() + (n - k), nums.end());
  reverse(nums.begin(), nums.end());
}

int main() {
  vector<int> nums{1, 2, 3, 4, 5, 6, 7};
  rotate(nums, 3);
  for (auto n : nums) {
    cout << n << " ";
  }
  return 0;
}