#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * Function to find two numbers in an array whose sum is equal to a given
 * target.
 *
 * @param nums vector of integers representing the array
 * @param target integer representing the target sum
 * @return vector of integers representing the indices of the two numbers
 */
vector<int> twoSum(vector<int> &nums, int target) {
  // Create a hashmap to store numbers and their indices
  unordered_map<int, int> hm;

  // Iterate through the array
  for (int i = 0; i < nums.size(); ++i) {
    // If the complement (target - nums[i]) is already in the map
    if (hm.find(target - nums[i]) != hm.end()) {
      // Return the indices of the two numbers
      return {hm[target - nums[i]], i};
    } else {
      // Store the number and its index in the map
      hm[nums[i]] = i;
    }
  }

  // If no two numbers with the target sum are found, return an empty vector
  return {};
}

int main() {
  vector<int> nums = {2, 7, 11, 15};
  vector<int> ans = twoSum(nums, 9);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}