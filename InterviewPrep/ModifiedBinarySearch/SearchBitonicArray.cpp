#include <iostream>
#include <vector>
using namespace std;

/*
* Given a Bitonic array, find if a given ‘key’ is present in it. An array is
* considered bitonic if it is monotonically increasing and then monotonically
* decreasing. Monotonically increasing or decreasing means that for any index i
* in the array arr[i] != arr[i+1].

* Write a function to return the index of the ‘key’. If the ‘key’ is not
* present, return -1.
*/

int binarySearch(vector<int>& arr, int key, int s, int e) {
  while (s <= e) {
    int m = s + (e - s) / 2;
    if (key == arr[m]) {
      return m;
    }

    if (arr[s] < arr[e]) {
      // Ascending order
      if (arr[m] > key) {
        e = m - 1;
      } else if (arr[m] < key) {
        s = m + 1;
      }
    } else {
      // Descending order
      if (arr[m] > key) {
        s = m + 1;
      } else if (arr[m] < key) {
        e = m - 1;
      }
    }
  }
  return -1;
}

int findMax(vector<int>& arr) {
  int s = 0, e = arr.size() - 1;
  while (s < e) {
    int m = s + (e - s) / 2;
    if (arr[m] > arr[m + 1]) {
      e = m;
    } else if (arr[m] < arr[m + 1]) {
      s = m + 1;
    }
  }

  // at the end of the while loop start == end
  return s;
}

int search(vector<int>& arr, int key) {
  int maxIndex = findMax(arr);
  int result = -1;
  result = binarySearch(arr, key, 0, maxIndex);
  if (result != -1) {
    return result;
  }
  return binarySearch(arr, key, maxIndex + 1, arr.size() - 1);
}

int main() {
  vector<int> arr{1, 3, 8, 4, 3};
  cout << search(arr, 4);
  return 0;
}