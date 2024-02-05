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
// 11,71,116 - 21,600 = 11,49,516 (EPF)
// 11,49,516 - 1,00,000 = 10,49,516 (Mutual Funds)
// 10,49,516 - 32,807 = 10,16,709 (LIC)
// 10,16,709 - 2,38,824	= 7,77,885 (HRA)
// 7,77,885 - 27,388 = 7,50,497 (Medical Insurance)
// 7,50,497 - 1499 * 3 = 7,46,000 (Checkups)
// 7,46,000 - 28,843 = 7,17,157 (Papa Health Insurance Premium)
// 7,17,157 - 318 - 1000 - 3700 = 7,12,139 (Mumma Tests / Medicines)

// Tax Computation
//  2,50,001 - 5,00,000 (5 %) = 12,500
//  5,00,001 - 7,12,139 (20 %) = 42,427
//  Total = 54,927
//  Paid till now = 39,103
//  Tax remaining = 54,927 - 39,103 = 15,824
