#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// https://leetcode.com/problems/number-of-islands/
void dfs(vector<vector<char>>& grid, int r, int c) {
  if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() ||
      grid[r][c] == '0') {
    return;
  }

  grid[r][c] = '0';
  dfs(grid, r + 1, c);
  dfs(grid, r - 1, c);
  dfs(grid, r, c + 1);
  dfs(grid, r, c - 1);
}

void bfs(vector<vector<char>>& grid, int r, int c) {
  queue<pair<int, int>> q;
  grid[r][c] = '0';
  q.push({r, c});
  int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  while (!q.empty()) {
    pair<int, int> fn = q.front();
    q.pop();

    int row = fn.first, col = fn.second;

    for (int i = 0; i < 4; i++) {
      int nr = row + directions[i][0], nc = col + directions[i][1];
      if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() &&
          grid[nr][nc] == '1') {
        q.push({nr, nc});
        grid[nr][nc] = '0';
      }
    }
  }
}

int numIslandsDFS(vector<vector<char>>& grid) {
  int ROWS = grid.size();
  int COLS = grid[0].size();

  int result = 0;
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (grid[r][c] == '1') {
        dfs(grid, r, c);
        result++;
      }
    }
  }
  return result;
}

int numIslandsBFS(vector<vector<char>>& grid) {
  int ROWS = grid.size();
  int COLS = grid[0].size();

  int result = 0;
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (grid[r][c] == '1') {
        bfs(grid, r, c);
        result++;
      }
    }
  }
  return result;
}

int main() { return 0; }