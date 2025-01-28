#include <iostream>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1

// works, unoptimized
vector<int> getFloorAndCeil(int x, vector<int> &arr) {
  sort(arr.begin(), arr.end());
  int s = 0, e = arr.size() - 1;
  int fl = -1, ce = -1;
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (arr[mid] < x) {
      fl = mid;
      s = mid + 1;
    } else if (arr[mid] > x) {
      ce = mid;
      e = mid - 1;
    } else {
      fl = mid;
      ce = mid;
    }
  }
  if (fl != -1 && ce != -1) {
    return {arr[fl], arr[ce]};
  } else if (fl != -1 && ce == -1) {
    return {arr[fl], -1};
  }
  return {-1, arr[ce]};
}

// o(n): as required by the question
vector<int> getFloorAndCeil(int x, vector<int> &arr) {
  int fl = -1, ce = -1;

  bool flag = false;
  int ans = INT_MAX;

  for (int a : arr) {
    if (a <= x) {
      fl = max(fl, a);
    }
    if (a >= x) {
      flag = true;
      ans = min(ans, a);
    }
  }

  if (flag) {
    ce = ans;
  }

  return {fl, ce};
}

int main() { return 0; }
