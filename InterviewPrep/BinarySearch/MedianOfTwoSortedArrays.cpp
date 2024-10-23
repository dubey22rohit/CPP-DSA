#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/median-of-two-sorted-arrays/

// This works but is not optimal, this is O(m + n)
// The question asks for O(log(m + n))
// TODO: Check the optimal solution
// https://neetcode.io/roadmap > Binary Search > Median of Two Sorted Arrays
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  vector<int> merged;
  int i = 0, j = 0;
  while (i < nums1.size() && j < nums2.size()) {
    if (nums1[i] < nums2[j]) {
      merged.push_back(nums1[i]);
      i++;
    } else if (nums1[i] > nums2[j]) {
      merged.push_back(nums2[j]);
      j++;
    } else {
      merged.push_back(nums1[i]);
      merged.push_back(nums2[j]);
      i++;
      j++;
    }
  }
  while (i < nums1.size()) {
    merged.push_back(nums1[i]);
    i++;
  }
  while (j < nums2.size()) {
    merged.push_back(nums2[j]);
    j++;
  }

  int s = 0, e = merged.size() - 1;
  int mid = s + (e - s) / 2;
  if (merged.size() % 2 == 0) {
    return (double)((merged[mid] + merged[mid + 1])) / 2;
  }
  return (double)(merged[mid]);
}
int main() {
  vector<int> nums1{1, 3};
  vector<int> nums2{2};

  cout << findMedianSortedArrays(nums1, nums2);
  return 0;
}