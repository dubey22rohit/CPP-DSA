#include <iostream>
#include <vector>
using namespace std;

/*
* Given an array of numbers sorted in an ascending order, find the ceiling of a
* given number ‘key’. The ceiling of the ‘key’ will be the smallest element in
* the given array greater than or equal to the ‘key’.

* Write a function to return the index of the ceiling of the ‘key’. If there
* isn’t any ceiling return -1.
*/

int searchCeilingOfANumber(vector<int> &arr, int key) {
  // If the key is greater than the greatest element in the array;
  if (key > arr[arr.size() - 1]) {
    return -1;
  }

  int start = 0, end = arr.size() - 1;
  int mid;
  while (start <= end) {
    mid = start + (end - start) / 2;
    if (arr[mid] > key) {
      end = mid - 1;
    } else if (arr[mid] < key) {
      start = mid + 1;
    } else {
      return mid;
    }
  }

  return start;
}

int main() {
  vector<int> arr{4, 6, 10};

  cout << searchCeilingOfANumber(arr, -1) << endl;
  return 0;
}
