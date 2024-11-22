#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    int minIndex = i;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] < nums[minIndex]) {
        minIndex = j;
      }
    }
    int temp = nums[i];
    nums[i] = nums[minIndex];
    nums[minIndex] = temp;
  }
}

int main() {
  vector<int> nums{5, 1, 4, 3, 2};
  selectionSort(nums);
  for (int n : nums) {
    cout << n << ", ";
  }
  return 0;
}