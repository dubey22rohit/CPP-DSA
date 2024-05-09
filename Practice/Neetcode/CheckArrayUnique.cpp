#include <iostream>
#include <vector>
using namespace std;

bool checkArrayUnique(vector<int> &nums) {
  // hash set method like this will work only if each element in the array
  //  is <= array size
  vector<bool> hs(nums.size());
  for (int i = 0; i < nums.size(); i++) {
    if (hs[nums[i]]) {
      return false;
    }
    hs[nums[i]] = true;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    nums.push_back(a);
  }

  bool arrayUnique = checkArrayUnique(nums);
  cout << arrayUnique;

  return 0;
}
