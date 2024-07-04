#include <iostream>
#include <vector>
using namespace std;

// Given an array of sorted numbers, remove all duplicates from it. You should
// not use any extra space; after removing the duplicates in-place return the
// new length of the array.

// Just to return the length this works
static int remove1(vector<int> &arr) {
  int i = 0, j = 0;
  int len = 0;
  while (j < arr.size()) {
    len++;
    while (arr[i] == arr[j]) {
      j++;
    }
    i = j;
  }
  return len;
}

// correct solution
static int remove(vector<int> &arr) {
  int uniqueIndex = 1;
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[uniqueIndex - 1] != arr[i]) {
      arr[uniqueIndex] = arr[i];
      uniqueIndex++;
    }
  }
  return uniqueIndex;
}

int main() {
  vector<int> arr{2, 3, 3, 3, 6, 9, 9};
  cout << remove(arr);
  return 0;
}