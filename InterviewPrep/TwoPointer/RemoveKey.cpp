#include <iostream>
#include <vector>
using namespace std;

// Given an unsorted array of numbers and a target ‘key’, remove all instances
// of ‘key’ in-place and return the new length of the array.

static int remove(vector<int> &arr, int key) {
  int nextElement = 0;
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] != key) {
      arr[nextElement] = arr[i];
      nextElement++;
    }
  }
  return nextElement;
}

int main() {
  vector<int> arr{3, 2, 3, 6, 3, 10, 9, 3};
  cout << remove(arr, 3);
  return 0;
}