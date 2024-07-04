#include <iostream>
#include <vector>
using namespace std;

// Given an array of sorted numbers and a target sum,
// find a pair in the array whose sum is equal to the given target

// Write a function to return the indices of the two
// numbers(i.e.the pair) such that they add up to the given target.

// Similar to Two Sum from leetcode

static pair<int, int> search(const vector<int> &arr, int targetSum) {
  int left = 0, right = arr.size() - 1;
  while (left < right) {
    if (arr[left] + arr[right] < targetSum) {
      left++;
    } else if (arr[left] + arr[right] > targetSum) {
      right--;
    } else {
      return make_pair(left, right);
    }
  }
  return make_pair(-1, -1);
}
// The time complexity of the above algorithm will be 𝑂(𝑁)
// O(N), where ‘N’ is the total number of elements in the given array.
// The algorithm runs in constant space O(1)

int main() {
  vector<int> arr{2, 5, 9, 11};
  pair<int, int> ans = search(arr, 11);
  cout << ans.first << " " << ans.second << "\n";
  return 0;
}