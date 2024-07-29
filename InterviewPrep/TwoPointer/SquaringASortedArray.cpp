#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Given a sorted array of integers, squares each element from both ends
 * of the array and stores the squared values in a new array in descending
 * order.
 *
 * @param arr The sorted array of integers.
 *
 * @return A new array containing the squared values of the input array in
 * descending order.
 */
static vector<int> makeSquares(const vector<int> &arr) {
  // Initialize variables
  int n = arr.size();            // Size of the input array
  vector<int> squares(n);        // New array to store squared values
  int highestSquareIdx = n - 1;  // Index of the highest squared value
  int left = 0,
      right = n - 1;  // Pointers to the left and right ends of the array

  // Two-pointer approach: move the pointers towards each other, squaring the
  // elements and storing the squared values in the new array in descending
  // order
  while (left <= right) {
    // Calculate the squares of the current elements
    int leftsq = arr[left] * arr[left];
    int rightsq = arr[right] * arr[right];

    // Determine which square to store and move the corresponding pointer
    if (leftsq > rightsq) {
      squares[highestSquareIdx--] = leftsq;
      left++;
    } else {
      squares[highestSquareIdx--] = rightsq;
      right--;
    }
  }

  return squares;
}

int main() {
  const vector<int> arr{-2, -1, 0, 2, 3};
  const vector<int> ans = makeSquares(arr);
  for (const int a : ans) {
    cout << a << " ";
  }
  return 0;
}