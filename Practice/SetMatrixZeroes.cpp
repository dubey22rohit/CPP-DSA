#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix) {
  vector<pair<int, int>> indices;
  int rows = matrix.size();
  int cols = matrix[0].size();
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

int main() {
  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  setZeroes(matrix);
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
