#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height) {
  int l = 0, r = height.size() - 1;
  int maxArea = INT_MIN;
  while (l < r) {
    int lh = height[l];
    int rh = height[r];
    int currArea = min(lh, rh) * (r - l);
    maxArea = max(maxArea, currArea);
    if (lh < rh) {
      l++;
    } else {
      r--;
    }
  }
  return maxArea;
}

int main() {
  int n;
  cin >> n;

  vector<int> height(n);

  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    height.push_back(a);
  }

  int maxAr = maxArea(height);
  cout << maxAr;

  return 0;
}
