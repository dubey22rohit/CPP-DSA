#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
int findFloor(vector<int>& arr, int k) {
  int s = 0, e = arr.size() - 1;
  int ans = -1;
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (arr[mid] <= k) {
      ans = mid;
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }
  return ans;
}

int main() { return 0; }