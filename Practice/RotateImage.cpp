#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix) {
  int n = matrix.size();
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main() {
  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  rotate(matrix);
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
