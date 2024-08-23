#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Finds two numbers in a sorted array whose sum is equal to a given
 * target.
 *
 * @param numbers The sorted array of integers.
 * @param target The target sum.
 *
 * @return A vector of integers representing the indices of the two numbers.
 */
vector<int> twoSum(vector<int>& numbers, int target) {
  int i = 0, j = numbers.size() - 1;
  while (i < j) {
    int sum = numbers[i] + numbers[j];
    if (sum < target) {
      i++;  // Move the left pointer to the right
    } else if (sum > target) {
      j--;  // Move the right pointer to the left
    } else {
      return {i + 1, j + 1};  // Found the pair, return their indices
    }
  }
  return {};  // No pair with the target sum is found
}

int main() {
  vector<int> nums{2, 7, 11, 15};
  cout << twoSum(nums, 9)[0] << ", " << twoSum(nums, 9)[1] << endl;
  return 0;
}