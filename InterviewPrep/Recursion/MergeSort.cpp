#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums, int s, int e) {
  int mid = s + (e - s) / 2;
  int i = s, j = mid + 1;
  vector<int> temp;
  while (i <= mid && j <= e) {
    if (nums[i] < nums[j]) {
      temp.push_back(nums[i]);
      i++;
    } else {
      temp.push_back(nums[j]);
      j++;
    }
  }

  while (i <= mid) {
    temp.push_back(nums[i]);
    i++;
  }

  while (j <= e) {
    temp.push_back(nums[j]);
    j++;
  }

  for (int k = 0; k < temp.size(); ++k) {
    nums[s + k] = temp[k];
  }
}

void mergeSort(vector<int> &nums, int s, int e) {
  if (s >= e) {
    return;
  }

  int mid = s + (e - s) / 2;
  mergeSort(nums, s, mid);
  mergeSort(nums, mid + 1, e);
  merge(nums, s, e);
}

int main() {
  vector<int> nums = {5, 4, 3, 2, 1};
  mergeSort(nums, 0, nums.size() - 1);

  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}