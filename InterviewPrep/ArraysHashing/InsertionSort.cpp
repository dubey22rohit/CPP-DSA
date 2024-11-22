#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& nums) {
  for (int i = 1; i < nums.size(); i++) {
    int currVal = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > currVal) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = currVal;
  }
}

int main() {
  vector<int> nums{5, 1, 4, 3, 2};
  insertionSort(nums);
  for (int n : nums) {
    cout << n << ", ";
  }
  return 0;
}