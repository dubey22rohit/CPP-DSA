#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// https://leetcode.com/problems/sort-characters-by-frequency/
string frequencySort(string s) {
  unordered_map<char, int> hm;
  for (char ch : s) {
    hm[ch]++;
  }

  vector<pair<char, int>> freq(hm.begin(), hm.end());
  sort(freq.begin(), freq.end(),
       [](const auto &a, const auto &b) { return a.second > b.second; });

  string res;
  for (const auto &p : freq) {
    res += string(p.second, p.first);
  }
  return res;
}

int main() {
  cout << frequencySort("Aabb");
  return 0;
}