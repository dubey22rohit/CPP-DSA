#include <iostream>
#include <vector>
using namespace std;

/*
* Given an array of numbers which is sorted in ascending order and is rotated
‘k’ times around a pivot, find ‘k’.

You can assume that the array does not have any duplicates.
 */

int countRotations(vector<int>& arr) {
  int s = 0, e = arr.size() - 1;
  while (s < e) {
    int m = s + (e - s) / 2;

    if (m < e && arr[m] > arr[m + 1]) {
      return m + 1;
    }

    if (m > s && arr[m - 1] > arr[m]) {
      return m;
    }

    if (arr[s] < arr[m]) {
      s = m + 1;
    } else {
      e = m - 1;
    }
  }

  return 0;
}

int main() {
  vector<int> arr{4, 5, 1, 2, 3};
  cout << countRotations(arr);
  return 0;
}