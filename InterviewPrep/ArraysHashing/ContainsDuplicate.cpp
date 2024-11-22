#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief Checks if a vector contains any duplicate elements.
 *
 * @param nums The vector to be checked.
 * @return True if the vector contains any duplicate elements, false otherwise.
 *
 * This function uses an unordered_set to store the elements of the vector.
 * If the size of the unordered_set after inserting all the elements is
 * different from the size of the vector, it means that the vector contains
 * duplicate elements.
 */
bool containsDuplicate(vector<int>& nums) {
  // Create an unordered_set to store the elements of the vector
  unordered_set<int> ns(nums.begin(), nums.end());

  // If the size of the unordered_set after inserting all the elements is
  // different from the size of the vector, it means that the vector contains
  // duplicate elements.
  return ns.size() != nums.size();
}

/**
 * @brief Checks if a vector contains any duplicate elements using an
 * unordered_map.
 *
 * @param nums The vector to be checked.
 * @return True if the vector contains any duplicate elements, false otherwise.
 *
 * This function uses an unordered_map to store the elements of the vector.
 * If the element already exists in the map, it means that the vector contains
 * duplicate elements.
 */
bool containsDuplicateHm(vector<int>& nums) {
  // Create an unordered_map to store the elements of the vector
  unordered_map<int, int> hm;

  // Iterate over each element in the vector
  for (auto n : nums) {
    // If the element already exists in the map, it means that the vector
    // contains duplicate elements.
    if (hm.find(n) != hm.end()) {
      return true;
    }
    // Otherwise, increment the count of the element in the map.
    hm[n]++;
  }

  // If no duplicate elements are found, return false.
  return false;
}

int main() {
  vector<int> nums{1, 2, 3, 4};
  bool ans = containsDuplicate(nums);
  cout << ans;
  return 0;
}