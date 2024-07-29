#include <iostream>
#include <vector>
using namespace std;

// Given an array of unsorted numbers, find all unique triplets in it that add
// up to zero.

/**
 * @brief Finds all unique triplets in the given array that add up to zero.
 *
 * @param arr The array of integers.
 * @param targetSum The target sum.
 * @param left The starting index of the left pointer.
 * @param triplets The vector to store the triplets.
 *
 * This function uses two-pointer approach to find all unique triplets in the
 * array that add up to zero. It sorts the array first, then iterates through
 * the array, fixing one element, and using the other two pointers to find
 * the other two elements that add up to the target sum. It skips duplicate
 * elements to avoid duplicates in the result.
 */
void searchPair(vector<int> &arr, int targetSum, int left,
                vector<vector<int>> &triplets) {
  // Initialize pointers to the start and end of the array.
  int right = arr.size() - 1;

  // Iterate through the array.
  while (left < right) {
    // Calculate the sum of the current triplet.
    int currSum = arr[left] + arr[right];

    // If the sum is equal to the target sum, store the triplet and move the
    // pointers.
    if (currSum == targetSum) {
      triplets.push_back({-targetSum, arr[left], arr[right]});
      left++;
      right--;

      // Skip duplicate elements to avoid duplicates in the result.
      while (left < right && arr[left] == arr[left - 1]) {
        left++;
      }
      while (left < right && arr[right] == arr[right + 1]) {
        right--;
      }
    } else if (currSum > targetSum) {
      // If the sum is greater than the target sum, move the right pointer to
      // the right to decrease the sum.
      right--;
    } else {
      // If the sum is less than the target sum, move the left pointer to the
      // right to increase the sum.
      left++;
    }
  }
}

/**
 * @brief Finds all unique triplets in the given array that add up to zero.
 *
 * @param arr The array of integers.
 * @return A vector of vectors, where each inner vector represents a triplet
 * that adds up to zero.
 *
 * This function uses two-pointer approach to find all unique triplets in the
 * array that add up to zero. It sorts the array first, then iterates through
 * the array, fixing one element, and using the other two pointers to find
 * the other two elements that add up to the target sum. It skips duplicate
 * elements to avoid duplicates in the result.
 */
vector<vector<int>> searchTriplets(vector<int> &arr) {
  // The vector to store the triplets.
  vector<vector<int>> triplets;

  // Sort the array.
  sort(arr.begin(), arr.end());

  // Iterate through the array.
  for (int i = 0; i < arr.size(); ++i) {
    // Skip duplicate elements.
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }

    // Search for a pair that adds up to -arr[i].
    searchPair(arr, -arr[i], i + 1, triplets);
  }

  // Return the triplets.
  return triplets;
}

int main() {
  vector<int> arr{-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans = searchTriplets(arr);
  for (auto a : ans) {
    for (auto b : a) {
      cout << b << ", ";
    }
    cout << "\n";
  }
  return 0;
}