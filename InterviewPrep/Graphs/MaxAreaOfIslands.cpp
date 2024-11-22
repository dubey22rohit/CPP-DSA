#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/max-area-of-island/
// TC: O(m * n)
int dfs(vector<vector<int>>& grid, int r, int c) {
  if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() ||
      grid[r][c] == 0) {
    return 0;
  }
  grid[r][c] = 0;

  return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + dfs(grid, r, c + 1) +
         dfs(grid, r, c - 1);
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
  int ROWS = grid.size(), COLS = grid[0].size();
  int maxArea = 0;
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (grid[r][c] == 1) {
        maxArea = max(maxArea, dfs(grid, r, c));
      }
    }
  }
  return maxArea;
}

int main() { return 0; }