#include <iostream>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/second-largest3735/1
int print2largest(vector<int> &arr) {
  if (arr.size() < 2) {
    return -1;
  }
  int l = INT_MIN, sl = INT_MIN;
  for (auto a : arr) {
    if (a > l) {
      sl = l;
      l = a;
    } else if (a > sl && a < l) {
      sl = a;
    }
  }
  if (sl == INT_MIN) {
    return -1;
  }

  return sl;
}

int main() {
  vector<int> arr = {12, 35, 1, 10, 34, 1};
  cout << print2largest(arr);
  return 0;
}