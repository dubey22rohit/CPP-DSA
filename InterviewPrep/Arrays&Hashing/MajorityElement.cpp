#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// https://leetcode.com/problems/majority-element

// Accepted by leetcode, this will only work if majEl count is > N / 2;
int majorityElement(vector<int> &nums) {
  int majEl = nums[0];
  int cnt = 0;
  for (auto n : nums) {
    if (n == majEl) {
      cnt++;
    } else {
      cnt--;
    }
    if (cnt < 0) {
      majEl = n;
      cnt = 1;
    }
  }
  return majEl;
}

int majorityElementHm(vector<int> &nums) {
  unordered_map<int, int> hm;
  for (auto n : nums) {
    hm[n]++;
  }

  int majEl = 0;
  int mostOcc = INT_MIN;
  for (auto it : hm) {
    if (it.second > mostOcc) {
      mostOcc = it.second;
      majEl = it.first;
    }
  }
  return majEl;
}

int main() {
  vector<int> nums{2, 2, 1, 1, 1, 3, 2, 2};
  cout << majorityElement(nums) << endl;
  cout << majorityElementHm(nums) << endl;
  return 0;
}