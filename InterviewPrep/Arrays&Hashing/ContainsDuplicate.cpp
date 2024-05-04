#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
  unordered_set<int> ns(nums.begin(), nums.end());
  return ns.size() != nums.size();
}

int main() {
  vector<int> nums{1, 2, 3, 4};
  bool ans = containsDuplicate(nums);
  cout << ans;
  return 0;
}