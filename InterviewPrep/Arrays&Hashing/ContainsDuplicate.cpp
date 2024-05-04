#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
  unordered_set<int> ns(nums.begin(), nums.end());
  return ns.size() != nums.size();
}

bool containsDuplicateHm(vector<int>& nums) {
  unordered_map<int, int> hm;
  for (auto n : nums) {
    if (hm.find(n) != hm.end()) {
      return true;
    }
    hm[n]++;
  }
  return false;
}

int main() {
  vector<int> nums{1, 2, 3, 4};
  bool ans = containsDuplicate(nums);
  cout << ans;
  return 0;
}