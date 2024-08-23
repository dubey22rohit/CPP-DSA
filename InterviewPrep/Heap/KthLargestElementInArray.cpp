#include <iostream>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
  priority_queue<int, vector<int>, less<int>> pq{nums.begin(), nums.end()};
  while (k > 1) {
    pq.pop();
    k--;
  }
  return pq.top();
}

int findKthLargestRutimeOptimized(vector<int>& nums, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < nums.size(); ++i) {
    if (pq.size() < k) {
      pq.push(nums[i]);
    } else if (!pq.empty() && pq.top() < nums[i]) {
      pq.pop();
      pq.push(nums[i]);
    }
  }
  return pq.top();
}

int main() {
  vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
  cout << findKthLargest(nums, 4);
  return 0;
}