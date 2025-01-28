#include <iostream>
#include <vector>
using namespace std;

/*
* Given an array of numbers which is sorted in ascending order and also rotated
by some arbitrary number, find if a given ‘key’ is present in it.

Write a function to return the index of the ‘key’ in the rotated array. If the
‘key’ is not present, return -1. You can assume that the given array does not
have any duplicates.
 */

// O(logN)
int search(vector<int>& arr, int key) {
  int s = 0, e = arr.size() - 1;
  while (s <= e) {
    int m = s + (e - s) / 2;
    if (arr[m] == key) {
      return m;
    }
    if (arr[s] <= arr[m]) {
      // left sorted portion
      if (key > arr[m] || key < arr[s]) {
        s = m + 1;
      } else {
        e = m - 1;
      }
    } else {
      // right sorted portion
      if (key < arr[m] || key > arr[e]) {
        e = m - 1;
      } else {
        s = m + 1;
      }
    }
  }
  return -1;
}

int main() {
  vector<int> arr{4, 5, 1, 2, 3};
  cout << search(arr, 5);
  return 0;
}