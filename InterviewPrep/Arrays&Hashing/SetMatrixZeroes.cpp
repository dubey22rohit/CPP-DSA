#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/set-matrix-zeroes/

void setZeroes(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix[0].size();

  vector<pair<int, int>> indices;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 0) {
        for (int k = 0; k < cols; k++) {
          indices.push_back({i, k});
        }
        for (int l = 0; l < rows; l++) {
          indices.push_back({l, j});
        }
      }
    }
  }
  for (int i = 0; i < indices.size(); i++) {
    matrix[indices[i].first][indices[i].second] = 0;
  }
}

int main() { return 0; }