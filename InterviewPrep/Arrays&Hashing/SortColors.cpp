#include <iostream>
#include <vector>
using namespace std;
void sortColors(vector<int>& nums) {
  int low = 0, mid = 0, high = nums.size() - 1;
  while (mid <= high) {
    switch (nums[mid]) {
      case 0:
        swap(nums[low], nums[mid]);
        low++;
        mid++;
        break;
      case 1:
        mid++;
        break;
      case 2:
        swap(nums[mid], nums[high]);
        high--;
        break;
    }
  }
}

int main() {
  vector<int> nums{0, 1, 2, 1, 2, 0, 1};
  sortColors(nums);
  for (auto n : nums) {
    cout << n << " ";
  }
  return 0;
}