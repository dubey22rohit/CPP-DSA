#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/pacific-atlantic-water-flow/

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
  int ROWS = heights.size();
  int COLS = heights[0].size();

  vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
  vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

  for (int c = 0; c < COLS; c++) {
    dfs(0, c, pac, heights);
    dfs(ROWS - 1, c, atl, heights);
  }

  for (int r = 0; r < ROWS; r++) {
    dfs(r, 0, pac, heights);
    dfs(r, COLS - 1, atl, heights);
  }

  vector<vector<int>> result;
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (pac[r][c] && atl[r][c]) {
        result.push_back({r, c});
      }
    }
  }

  return result;
}

void dfs(int r, int c, vector<vector<bool>>& ocean,
         vector<vector<int>>& heights) {
  ocean[r][c] = true;
  for (const auto& dir : directions) {
    int nr = r + dir.first, nc = c + dir.second;
    if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() &&
        !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
      dfs(nr, nc, ocean, heights);
    }
  }
}

int main() { return 0; }