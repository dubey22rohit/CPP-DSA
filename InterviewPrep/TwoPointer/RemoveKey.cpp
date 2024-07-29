#include <iostream>
#include <vector>
using namespace std;

// Given an unsorted array of numbers and a target ‘key’, remove all instances
// of ‘key’ in-place and return the new length of the array.

/**
 * Given an unsorted array of numbers and a target 'key', remove all instances
 * of 'key' in-place and return the new length of the array.
 *
 * @param arr The array from which to remove the key.
 * @param key The key to remove from the array.
 * @return The new length of the array after removing the key.
 */
int remove(vector<int> &arr, int key) {
  // Initialize the next element to be filled with a value not equal to the key
  int nextElement = 0;

  // Iterate through the array
  for (int i = 0; i < arr.size(); ++i) {
    // If the current element is not equal to the key, copy it to the next
    // element and increment the next element index
    if (arr[i] != key) {
      arr[nextElement] = arr[i];
      nextElement++;
    }
  }

  // Return the new length of the array after removing the key
  return nextElement;
}

int main() {
  vector<int> arr{3, 2, 3, 6, 3, 10, 9, 3};
  cout << remove(arr, 3);
  return 0;
}