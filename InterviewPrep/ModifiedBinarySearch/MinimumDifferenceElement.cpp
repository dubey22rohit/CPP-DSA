#include <iostream>
#include <vector>
using namespace std;

/*
 * Given an array of numbers sorted in ascending order, find the element in the
 * array that has the minimum difference with the given ‘key’.
 */

int searchMinDiffElement(vector<int>& arr, int key) {
  if (key < arr[0]) {
    return arr[0];
  }
  if (key > arr[arr.size() - 1]) {
    return arr[arr.size() - 1];
  }
  int s = 0, e = arr.size() - 1;
  while (s <= e) {
    int m = s + (e - s) / 2;
    if (arr[m] > key) {
      e = m - 1;
    } else if (arr[m] < key) {
      s = m + 1;
    } else {
      return arr[m];
    }
  }

  if (abs(arr[s] - key) < abs(arr[e] - key)) {
    return arr[s];
  }

  return arr[e];
}

int main() {
  vector<int> arr{1, 3, 8, 10, 15};
  cout << searchMinDiffElement(arr, 12);
  return 0;
}