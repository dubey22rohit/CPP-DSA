#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// https://leetcode.com/problems/rotting-oranges/
int orangesRotting(vector<vector<int>>& grid) {
  int ROWS = grid.size();
  int COLS = grid[0].size();

  queue<pair<int, int>> q;
  int fresh = 0;
  int time = 0;
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (grid[r][c] == 1) {
        fresh++;
      } else if (grid[r][c] == 2) {
        q.push({r, c});
      }
    }
  }

  vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  while (fresh > 0 && !q.empty()) {
    int qlen = q.size();
    for (int i = 0; i < qlen; i++) {
      auto [row, col] = q.front();
      q.pop();

      for (const auto& dir : directions) {
        int r = row + dir.first, c = col + dir.second;
        if (r >= 0 && r < ROWS && c >= 0 && c < COLS && grid[r][c] == 1) {
          grid[r][c] = 2;
          fresh--;
          q.push({r, c});
        }
      }
    }
    time++;
  }

  return fresh == 0 ? time : -1;
}

int main() { return 0; }