#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
  int n = nums.size();
  unordered_map<int, int> mp;
  for (auto num : nums) {
    mp[num]++;
  }

  vector<vector<int>> buckets(n + 1);
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    buckets[it->second].push_back(it->first);
  }

  vector<int> result;
  for (int i = n; i >= 0; --i) {
    if (result.size() >= k) {
      break;
    }
    if (!buckets[i].empty()) {
      // Inserting multiple values in a vector at a specified position
      // std::vector.insert(position, start, end);
      result.insert(result.end(), buckets[i].begin(), buckets[i].end());
    }
  }
  return result;
}

int main() {
  vector<int> nums{1, 1, 1, 2, 2, 3};
  vector<int> ans = topKFrequent(nums, 2);

  for (auto n : ans) {
    cout << n << ", ";
  }

  return 0;
}
