#include <iostream>
#include <vector>
using namespace std;

void printAllCombinationsHelper(vector<int>& nums, int sum, int index,
                                vector<int>& curr, int currSum) {
  if (index == nums.size()) {
    if (currSum == sum) {
      cout << "[";
      for (auto n : curr) {
        cout << n << " ";
      }
      cout << "]";
      cout << endl;
      return;
    }
    return;
  }

  currSum += nums[index];
  curr.push_back(nums[index]);
  printAllCombinationsHelper(nums, sum, index + 1, curr, currSum);

  currSum -= nums[index];
  curr.pop_back();
  printAllCombinationsHelper(nums, sum, index + 1, curr, currSum);
}

void printAllCombinations(vector<int>& nums, int sum) {
  vector<int> curr;
  return printAllCombinationsHelper(nums, sum, 0, curr, 0);
}

int main() {
  vector<int> nums{3, 1, 2, 4, 5};
  printAllCombinations(nums, 5);
  return 0;
}