#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
  int n = nums.size();
  vector<int> result(n, 1);

  int leftRunningProduct = 1;
  for (int i = 0; i < n; ++i) {
    result[i] = leftRunningProduct;
    leftRunningProduct *= nums[i];
  }

  int rightRunningProduct = 1;
  for (int i = n - 1; i >= 0; --i) {
    result[i] *= rightRunningProduct;
    rightRunningProduct *= nums[i];
  }

  return result;
}

int main() {
  vector<int> nums{1, 2, 3, 4};
  vector<int> result = productExceptSelf(nums);
  for (auto r : result) {
    cout << r << " ";
  }
  return 0;
}