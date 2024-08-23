#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &height) {
  int l = 0, r = height.size() - 1;
  int maxL = height[l], maxR = height[r];
  int res = 0;

  while (l < r) {
    if (maxL < maxR) {
      l++;
      maxL = max(maxL, height[l]);
      res += maxL - height[l];
    } else {
      r--;
      maxR = max(maxR, height[r]);
      res += maxR - height[r];
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;

  vector<int> height;

  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    height.push_back(a);
  }

  int trappedWater = trap(height);
  cout << trappedWater;

  return 0;
}
