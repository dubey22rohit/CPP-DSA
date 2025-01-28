#include <iostream>
#include <vector>
using namespace std;

/*
* Given a sorted array of numbers, find if a given number ‘key’ is present in
the array. Though we know that the array is sorted, we don’t know if it’s sorted
in ascending or descending order. You should assume that the array can have
duplicates.

Write a function to return the index of the ‘key’ if it is present in the array,
otherwise return -1.
 */

int search(vector<int>& arr, int key, bool findMaxIndex) {
  int keyIndex = -1;
  int s = 0, e = arr.size() - 1;
  int mid;
  while (s <= e) {
    mid = s + (e - s) / 2;
    if (arr[mid] > key) {
      e = mid - 1;
    } else if (arr[mid] < key) {
      s = mid + 1;
    } else {
      keyIndex = mid;
      if (findMaxIndex) {
        s = mid + 1;  // search ahead to find the last index of 'key'
      } else {
        e = mid - 1;  // search behind to find the first index of 'key'
      }
    }
  }
  return keyIndex;
}

pair<int, int> findRange(vector<int>& arr, int key) {
  pair<int, int> result(-1, -1);
  result.first = search(arr, key, false);
  if (result.first != -1) {
    result.second = search(arr, key, true);
  }
  return result;
}

int main() {
  vector<int> arr{4, 6, 6, 6, 9};
  pair<int, int> result = findRange(arr, 6);
  cout << result.first << " " << result.second;
  return 0;
}