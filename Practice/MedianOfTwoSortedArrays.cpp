#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  priority_queue<int, vector<int>, less<int>> pq;
  for (auto n : nums1) {
    pq.push(n);
  }
  for (auto n : nums2) {
    pq.push(n);
  }

  int size = pq.size();
  double mid = ceil(double(size) / double(2)) - 1;
  while (mid--) {
    pq.pop();
  }
  if (size % 2 != 0) {
    return pq.top();
  }
  int e1 = pq.top();
  pq.pop();
  int e2 = pq.top();
  return double(e1 + e2) / 2;
}

double findMedianSortedArraysOptimized(vector<int> &nums1, vector<int> &nums2) {
  vector<int> med;
  for (auto n : nums1) {
    med.push_back(n);
  }
  for (auto n : nums2) {
    med.push_back(n);
  }

  sort(med.begin(), med.end());
  int n = med.size();

  return n % 2 ? med[n / 2] : ((med[n / 2 - 1] + med[n / 2]) / 2.0);
}

int main() {
  vector<int> nums1;
  vector<int> nums2;
  int m, n;
  cin >> m >> n;
  int a;
  for (int i = 0; i < m; i++) {
    cin >> a;
    nums1.push_back(a);
  }

  for (int i = 0; i < n; i++) {
    cin >> a;
    nums2.push_back(a);
  }

  double median = findMedianSortedArraysOptimized(nums1, nums2);
  cout << median;

  return 0;
}
