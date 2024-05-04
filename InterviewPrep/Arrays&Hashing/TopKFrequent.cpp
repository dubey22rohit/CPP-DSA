#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
  int n = nums.size();
  unordered_map<int, int> hmp;
  for (auto n : nums) {
    hmp[n]++;
  }

  vector<vector<int>> buckets(n + 1);
  unordered_map<int, int>::iterator it = hmp.begin();
  while (it != hmp.end()) {
    buckets[it->second].push_back(it->first);
    ++it;
  }

  vector<int> ans;
  for (int i = n; i >= 0; --i) {
    if (ans.size() >= k) {
      break;
    }
    if (!buckets[i].empty()) {
      ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
    }
  }
  return ans;
}

int main() {
  vector<int> nums{1, 1, 1, 2, 2, 3};
  vector<int> ans = topKFrequent(nums, 2);
  for (auto a : ans) {
    cout << a << ", ";
  }
  return 0;
}