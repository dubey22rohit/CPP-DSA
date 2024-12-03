#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/house-robber/
// TODO: Revise

int rob(vector<int>& nums) {
  int rob1 = 0, rob2 = 0;
  for (int n : nums) {
    int temp = max(rob1 + n, rob2);
    rob1 = rob2;
    rob2 = temp;
  }
  return rob2;
}

int main() { return 0; }