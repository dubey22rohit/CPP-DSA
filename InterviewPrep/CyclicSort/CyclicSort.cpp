#include <iostream>
#include <vector>
using namespace std;

// We are given an array containing ‘n’ objects. Each object, when created, was
// assigned a unique number from 1 to ‘n’ based on their creation sequence. This
// means that the object with sequence number ‘3’ was created just before the
// object with sequence number ‘4’.

// Write a function to sort the objects in - place on their creation sequence
// number in O(n) O(n) and without any extra space.For simplicity, let’s assume
// we are passed an integer array containing only the sequence numbers, though
// each number is actually an object.

/**
 * Sorts the given vector of integers in-place according to their original
 * creation sequence.
 *
 * @param nums the vector of integers to be sorted
 *
 * @throws None
 */
void sort(vector<int>& nums) {
  // Initialize the index to the first element of the vector
  int i = 0;

  // Iterate over the vector until i reaches the end
  while (i < nums.size()) {
    // Calculate the index of the element to be swapped with the current element
    int j = nums[i] - 1;

    // If the element at index i is not already in its correct position
    if (nums[i] != nums[j]) {
      // Swap the current element with the element at index j
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    } else {
      // If the element is already in its correct position, move to the next
      // element
      ++i;
    }
  }
}

/*
Time complexity:
The time complexity of the above algorithm is O(n).
Although we are not incrementing the index i when swapping the numbers, this
will result in more than ‘n’ iterations of the loop, but in the worst-case
scenario, the while loop will swap a total of ‘n-1’ numbers and once a number is
at its correct index, we will move on to the next number by incrementing i. So
overall, our algorithm will take O(n) + O(n-1)
which is asymptotically equivalent to O(n)

Space Complexity:
The algorithm runs in constant space
O(1)
*/

int main() {
  vector<int> nums{2, 6, 4, 3, 1, 5};
  sort(nums);
  for (int n : nums) {
    cout << n << ", ";
  }

  return 0;
}