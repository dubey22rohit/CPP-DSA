#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutiveUsingSet(vector<int> &nums) {
  unordered_set<int> ns(nums.begin(), nums.end());
  int lon = 0;
  for (auto &n : ns) {
    if (!ns.count(n - 1)) {
      int len = 1;
      while (ns.count(n + len)) {
        ++len;
      }
      lon = max(lon, len);
    }
  }
  return lon;
}

int longestConsecutive(vector<int> &nums) {
  if (nums.size() == 0) {
    return 0;
  }
  map<int, int> mp;
  for (auto n : nums) {
    mp[n]++;
  }

  map<int, int>::iterator it = mp.begin();

  int prev = it->first, ans = 1, oldAns = 0;
  ++it;
  while (it != mp.end()) {
    if (abs(it->first - prev) <= 1) {
      ans++;
    } else {
      oldAns = max(ans, oldAns);
      ans = 1;
    }
    prev = it->first;
    ++it;
  }
  oldAns = max(ans, oldAns);
  return oldAns;
}

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);

  int a;
  while (n--) {
    cin >> a;
    nums.push_back(a);
  }

  int lc = longestConsecutive(nums);
  cout << "\n" << lc;

  return 0;
}
