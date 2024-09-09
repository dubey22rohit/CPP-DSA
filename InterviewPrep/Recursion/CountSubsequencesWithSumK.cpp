#include <iostream>
#include <vector>
using namespace std;

int countOfSubsequencesHelper(vector<int>& nums, int sum, vector<int>& curr,
                              int currSum, int index) {
  if (currSum > sum) {
    return 0;
  }
  if (index == nums.size()) {
    if (currSum == sum) {
      return 1;
    }
    return 0;
  }
  currSum += nums[index];
  curr.push_back(nums[index]);
  int l = countOfSubsequencesHelper(nums, sum, curr, currSum, index + 1);

  currSum -= nums[index];
  curr.pop_back();
  int r = countOfSubsequencesHelper(nums, sum, curr, currSum, index + 1);

  return l + r;
}

int countOfSubsequences(vector<int>& nums, int sum) {
  vector<int> curr;
  return countOfSubsequencesHelper(nums, sum, curr, 0, 0);
}

int main() {
  vector<int> nums{1, 2, 3, 4, 5};
  cout << countOfSubsequences(nums, 5);
  return 0;
}