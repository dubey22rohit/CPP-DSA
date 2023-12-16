#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == nums[i + 1]) {
      return nums[i];
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
