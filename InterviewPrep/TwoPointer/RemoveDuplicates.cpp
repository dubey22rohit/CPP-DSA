#include <iostream>
#include <vector>
using namespace std;

// Given an array of sorted numbers, remove all duplicates from it. You should
// not use any extra space; after removing the duplicates in-place return the
// new length of the array.

// Just to return the length this works
int remove1(vector<int> &arr) {
  int i = 0, j = 0;
  int len = 0;
  while (j < arr.size()) {
    len++;
    while (arr[i] == arr[j]) {
      j++;
    }
    i = j;
  }
  return len;
}

/**
 * Removes duplicates from a sorted array in-place.
 *
 * @param arr The sorted array to remove duplicates from.
 * @return The new length of the array after removing duplicates.
 *
 * @throws None.
 */
int remove(vector<int> &arr) {
  // Start with the second element in the array because the first element
  // is always unique.
  int uniqueIndex = 1;

  // Iterate through the array, starting from the second element.
  for (int i = 1; i < arr.size(); ++i) {
    // If the current element is different from the previous element,
    // it is a unique element.
    if (arr[uniqueIndex - 1] != arr[i]) {
      // Copy the current element to the next unique index.
      arr[uniqueIndex] = arr[i];
      // Increment the unique index to track the next unique element.
      uniqueIndex++;
    }
  }

  // Return the new length of the array after removing duplicates.
  return uniqueIndex;
}

int main() {
  vector<int> arr{2, 3, 3, 3, 6, 9, 9};
  cout << remove(arr);
  return 0;
}