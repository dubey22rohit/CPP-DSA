#include <iostream>
using namespace std;

// https://leetcode.com/problems/assign-cookies/

int findContentChildren(vector<int>& g, vector<int>& s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  int sf = 0;
  int i = 0, j = 0;
  while (i < g.size() && j < s.size()) {
    if (s[j] >= g[i]) {
      sf++;
      i++;
    }
    j++;
  }
  return sf;
}

int main() { return 0; }