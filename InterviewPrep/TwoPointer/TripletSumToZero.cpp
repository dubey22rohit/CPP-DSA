#include <iostream>
#include <vector>
using namespace std;

// Given an array of unsorted numbers, find all unique triplets in it that add
// up to zero.

static void searchPair(vector<int> &arr, int targetSum, int left,
                       vector<vector<int>> &triplets) {
  int right = arr.size() - 1;
  while (left < right) {
    int currSum = arr[left] + arr[right];
    if (currSum == targetSum) {
      triplets.push_back({-targetSum, arr[left], arr[right]});
      left++;
      right--;
      while (left < right && arr[left] == arr[left - 1]) {
        left++;
      }
      while (left < right && arr[right] == arr[right + 1]) {
        right--;
      }
    } else if (targetSum > currSum) {
      left++;
    } else {
      right--;
    }
  }
}

static vector<vector<int>> searchTriplets(vector<int> &arr) {
  vector<vector<int>> triplets;
  sort(arr.begin(), arr.end());

  for (int i = 0; i < arr.size(); ++i) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    searchPair(arr, -arr[i], i + 1, triplets);
  }
  return triplets;
}

int main() {
  vector<int> arr{-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans = searchTriplets(arr);
  for (auto a : ans) {
    for (auto b : a) {
      cout << b << ", ";
    }
    cout << "\n";
  }
  return 0;
}