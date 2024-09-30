#include <iostream>
#include <vector>
using namespace std;

bool transportPossible(vector<int> &nums, int t) {
  int curr = 0;
  while (curr <= t) {
    if (curr == t) {
      return true;
    }
    curr = curr + nums[curr];
  }
  return false;
}

int main() {
  vector<int> nums;
  int n, t;
  cin >> n >> t;
  n--;
  while (n--) {
    int a;
    cin >> a;
    nums.push_back(a);
  }

  cout << (transportPossible(nums, t - 1) ? "YES" : "NO");
  return 0;
}