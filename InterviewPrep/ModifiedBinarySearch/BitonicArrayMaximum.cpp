#include <iostream>
#include <vector>
using namespace std;

/*
 * Find the maximum value in a given Bitonic array. An array is considered
 * bitonic if it is monotonically increasing and then monotonically decreasing.
 * Monotonically increasing or decreasing means that for any index i in the
 * array arr[i] != arr[i+1].
 */

int findMax(vector<int>& arr) {
  int s = 0, e = arr.size() - 1;
  while (s < e) {
    int m = s + (e - s) / 2;
    if (arr[m] <= arr[m + 1]) {
      s = m + 1;
    } else if (arr[m] > arr[m + 1]) {
      e = m;
    }
  }
  return arr[s];
}

int main() {
  vector<int> arr{1, 3, 8, 12, 4, 2};
  cout << findMax(arr);
  return 0;
}