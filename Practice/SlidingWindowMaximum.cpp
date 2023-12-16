#include <iostream>
#include <vector>
using namespace std;

// Brute force
vector<int> maxSlidingWindowBruteForce(vector<int> &nums, int k) {
  int i = 0, j = k - 1;
  vector<int> ans;
  while (j < nums.size()) {
    int windowMax = INT_MIN, x = i;
    while (x <= j) {
      windowMax = max(windowMax, nums[x]);
      x++;
    }
    ans.push_back(windowMax);
    i++;
    j++;
  }
  return ans;
}

vector<int> maxSlidingWindow(vector<int> &nums, int k) {}

int main() {
  vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
  vector<int> ans = maxSlidingWindowBruteForce(nums, 3);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}
