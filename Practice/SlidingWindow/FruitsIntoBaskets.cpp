#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Fruits into Baskets (medium)
// TC: O(N)
// The algorithm runs in constant space
// O(1) as there can be a maximum of three types of fruits stored in the
// frequency map.

int findLength(const vector<char> &arr) {
  int maxLength = 0;
  unordered_map<char, int> hm;
  int ws = 0;
  for (int we = 0; we < arr.size(); we++) {
    hm[arr[we]]++;
    while (hm.size() > 2) {
      hm[arr[ws]]--;
      if (hm[arr[ws]] == 0) {
        hm.erase(arr[ws]);
      }
      ws++;
    }
    maxLength = max(maxLength, we - ws + 1);
  }
  return maxLength;
}

// Leetcode equivalent: https://leetcode.com/problems/fruit-into-baskets/
int totalFruit(vector<int> &fruits) {
  unordered_map<int, int> hm;
  int maxLen = 0, ws = 0;
  for (int we = 0; we < fruits.size(); we++) {
    hm[fruits[we]]++;
    while (hm.size() > 2) {
      hm[fruits[ws]]--;
      if (hm[fruits[ws]] == 0) {
        hm.erase(fruits[ws]);
      }
      ws++;
    }
    maxLen = max(maxLen, we - ws + 1);
  }
  return maxLen;
}

int main() {
  vector<char> arr{'A', 'B', 'C', 'B', 'B', 'C'};
  int len = findLength(arr);
  cout << len;
}
