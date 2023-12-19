#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++) {
    int index = abs(nums[i]) - 1;
    nums[index] *= -1;
    if (nums[index] > 0) {
      return abs(nums[i]);
    }
  }
  return -1;
}

int main() {
  vector<int> nums;
  int n;
  cin >> n;
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    nums.push_back(a);
  }

  int repeatingInt = findDuplicate(nums);
  cout << repeatingInt;

  return 0;
}
