#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
  int l = 0, r = height.size() - 1;
  int maxL = height[l];
  int maxR = height[r];

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

int trapMoreReadable(vector<int>& height) {
  // Original formula for getting the water trapped is: min(l, r) - height[i];
  int l = 0, r = height.size() - 1;
  int maxL = height[l];
  int maxR = height[r];

  int res = 0;

  while (l < r) {
    if (maxL < maxR) {
      l++;
      int h = maxL - height[l];
      if (h > 0) {
        res += h;
      }
      maxL = max(maxL, height[l]);
    } else {
      r--;
      int h = maxR - height[r];
      if (h > 0) {
        res += h;
      }
      maxR = max(maxR, height[r]);
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
  int trappedWaterR = trapMoreReadable(height);

  cout << trappedWater << endl;
  cout << trappedWaterR;

  return 0;
}