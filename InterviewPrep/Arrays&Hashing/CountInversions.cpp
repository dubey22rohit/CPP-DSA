#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

// https://www.naukri.com/code360/problems/count-inversions_615?leftPanelTabValue=PROBLEM

// Brute force approach
ll getInversionsBF(ll *arr, int n) {
  ll ans = 0;
  for (ll i = 0; i < n - 1; i++) {
    for (ll j = i + 1; j < n; j++) {
      if (arr[i] > arr[j] && i < j) {
        ans++;
      }
    }
  }
  return ans;
}

int merge(vector<int> &nums, int low, int mid, int high) {
  int left = low, right = mid + 1;
  vector<int> temp;
  int cnt = 0;
  while (left <= mid && right <= high) {
    if (nums[left] <= nums[right]) {
      temp.push_back(nums[left]);
      left++;
    } else {
      cnt += (mid - left + 1);
      temp.push_back(nums[right]);
      right++;
    }
  }

  while (left <= mid) {
    temp.push_back(nums[left]);
    left++;
  }

  while (right <= high) {
    temp.push_back(nums[right]);
    right++;
  }

  for (int i = low; i <= high; i++) {
    nums[i] = temp[i - low];
  }

  return cnt;
}

int mergeSort(vector<int> &nums, int low, int high) {
  int cnt = 0;
  if (low >= high) {
    return cnt;
  }
  int mid = low + (high - low) / 2;
  cnt += mergeSort(nums, low, mid);
  cnt += mergeSort(nums, mid + 1, high);
  cnt += merge(nums, low, mid, high);
  return cnt;
}

int getInversions(vector<int> &nums) {
  return mergeSort(nums, 0, nums.size() - 1);
}

int main() {
  ll *arr = new ll[5]{2, 5, 1, 3, 4};
  cout << getInversionsBF(arr, 5) << endl;

  vector<int> nums{2, 5, 1, 3, 4};
  cout << getInversions(nums) << endl;

  return 0;
}