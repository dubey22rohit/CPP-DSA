#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/combination-sum-iii/
void dfs(int k, int n, int idx, vector<int> curr, vector<vector<int>>& result) {
  if (curr.size() >= k) {
    if (n == 0) {
      result.push_back(curr);
    }
    return;
  }

  for (int i = idx; i <= 9; i++) {
    curr.push_back(i);
    dfs(k, n - i, i + 1, curr, result);
    curr.pop_back();
  }
}

vector<vector<int>> combinationSum3(int k, int n) {
  vector<vector<int>> result;
  vector<int> curr;
  dfs(k, n, 1, curr, result);
  return result;
}

int main() {
  vector<vector<int>> result = combinationSum3(3, 7);
  for (vector<int> res : result) {
    cout << "[";
    for (int r : res) {
      cout << r << ", ";
    }
    cout << "]\n";
  }
  return 0;
}