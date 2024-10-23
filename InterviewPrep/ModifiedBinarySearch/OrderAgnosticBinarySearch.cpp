#include <iostream>
#include <vector>
using namespace std;

/*
 * Given a sorted array of numbers, find if a given number ‘key’ is present in
 * the array. Though we know that the array is sorted, we don’t know if it’s
 * sorted in ascending or descending order. You should assume that the array can
 * have duplicates.
 */

int search(vector<int> &arr, int key) {
  int start = 0, end = arr.size() - 1;
  int mid;
  bool isAscending = arr[start] < arr[end];
  while (start <= end) {
    mid = start + (end - start) / 2;

    if (key == arr[mid]) {
      return mid;
    }

    if (isAscending) {
      if (key < arr[mid]) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    } else {
      if (key < arr[mid]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
  }
  return -1;
}

int main() {
  vector<int> arr{1, 2, 3, 4, 5, 6, 7};

  cout << search(arr, 5) << endl;

  reverse(arr.begin(), arr.end());

  cout << search(arr, 5) << endl;

  return 0;
}