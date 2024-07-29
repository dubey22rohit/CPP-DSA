#include <iostream>
#include <vector>
using namespace std;

/**
 * Given an array of integers, calculate the product of all elements
 * except for the current element.
 *
 * @param nums The input array of integers.
 * @return A vector of integers representing the product of all elements
 *         except for the current element.
 */
vector<int> productExceptSelf(vector<int>& nums) {
  // Initialize the result vector with 1s.
  int n = nums.size();
  vector<int> result(n, 1);

  // Calculate the product of elements to the left of the current element.
  int leftRunningProduct = 1;
  for (int i = 0; i < n; ++i) {
    // Multiply the current leftRunningProduct with the current element.
    result[i] = leftRunningProduct;
    // Update leftRunningProduct to the product of the current element and
    // the previous leftRunningProduct.
    leftRunningProduct *= nums[i];
  }

  // Calculate the product of elements to the right of the current element.
  int rightRunningProduct = 1;
  for (int i = n - 1; i >= 0; --i) {
    // Multiply the current rightRunningProduct with the current element.
    result[i] *= rightRunningProduct;
    // Update rightRunningProduct to the product of the current element and
    // the previous rightRunningProduct.
    rightRunningProduct *= nums[i];
  }

  // Return the result vector.
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