#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums) {
  int n = nums.size();
  int j = -1;

  // Find the first zero position
  for (int i = 0; i < n; i++) {
    if (nums[i] == 0) {
      j = i;
      break;
    }
  }

  // If no zero is found, no need to do anything
  if (j == -1) {
    return;
  }

  // Move non-zero elements to the front and zeroes to the end
  for (int i = j + 1; i < n; i++) {
    if (nums[i] != 0) {
      swap(nums[i], nums[j]);
      j++;
    }
  }
}

int main() {
  vector<int> nums{1, 0, 1};
  moveZeroes(nums);
  for (auto n : nums) {
    cout << n << " ";
  }
  return 0;
}