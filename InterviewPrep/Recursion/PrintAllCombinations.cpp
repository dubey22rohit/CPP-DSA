#include <iostream>
#include <vector>
using namespace std;

void printAllCombinationsHelper(vector<int>& nums, int index,
                                vector<int>& curr) {
  if (index >= nums.size()) {
    cout << "[";
    for (auto n : curr) {
      cout << n << " ";
    }
    cout << "]";
    cout << endl;
    return;
  }
  curr.push_back(nums[index]);
  printAllCombinationsHelper(nums, index + 1, curr);
  curr.pop_back();
  printAllCombinationsHelper(nums, index + 1, curr);
}

// TC: O(2^n * n(printing the array))
void printAllCombinations(vector<int>& nums) {
  vector<int> curr;
  return printAllCombinationsHelper(nums, 0, curr);
}

int main() {
  vector<int> nums{3, 1, 2};
  printAllCombinations(nums);
  return 0;
}