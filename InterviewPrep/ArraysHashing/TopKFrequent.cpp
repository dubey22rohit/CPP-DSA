#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * Given an array of integers and an integer k, return the k most frequent
 * integers.
 *
 * @param nums vector of integers
 * @param k integer representing the number of most frequent integers to return
 * @return vector of integers representing the k most frequent integers
 */
vector<int> topKFrequent(vector<int>& nums, int k) {
  // Get the frequency of each integer in the input array
  int n = nums.size();
  unordered_map<int, int> hmp;
  for (auto n : nums) {
    hmp[n]++;
  }

  // Create a 2D vector to store the integers based on their frequency
  vector<vector<int>> buckets(n + 1);
  unordered_map<int, int>::iterator it = hmp.begin();
  while (it != hmp.end()) {
    buckets[it->second].push_back(it->first);
    ++it;
  }

  // Iterate through the buckets in descending order of frequency and add the
  // integers to the result
  vector<int> ans;
  for (int i = n; i >= 0; --i) {
    // If the result size is equal to k, we have collected all the k most
    // frequent integers
    if (ans.size() >= k) {
      break;
    }
    // If the bucket is not empty, add all the integers in the bucket to the
    // result
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