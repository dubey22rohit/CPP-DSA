#include <iostream>
#include <unordered_set>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_set<int> window;
  int l = 0;
  for (int r = 0; r < nums.size(); r++) {
    if (r - l > k) {
      window.erase(nums[l]);
      l++;
    }

    if (window.find(nums[r]) != window.end()) {
      return true;
    }

    window.insert(nums[r]);
  }
  return false;
}

int main() { return 0; }