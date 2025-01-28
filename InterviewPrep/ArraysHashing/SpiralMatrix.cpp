#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/spiral-matrix/description/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  if (matrix.size() == 0) {
    return {};
  }
  int t = 0, b = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
  int flag = 0;
  vector<int> result;
  while (t <= b && l <= r) {
    switch (flag) {
      case 0:
        for (int i = l; i <= r; i++) {
          result.push_back(matrix[t][i]);
        }
        t++;
        break;
      case 1:
        for (int i = t; i <= b; i++) {
          result.push_back(matrix[i][r]);
        }
        r--;
        break;
      case 2:
        for (int i = r; i >= l; i--) {
          result.push_back(matrix[b][i]);
        }
        b--;
        break;
      case 3:
        for (int i = b; i >= t; i--) {
          result.push_back(matrix[i][l]);
        }
        l++;
        break;
    }
    flag = (flag + 1) % 4;
  }
  return result;
}
int main() { return 0; }