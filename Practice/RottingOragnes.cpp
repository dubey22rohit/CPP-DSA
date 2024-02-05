#include <queue>
#include <vector>
using namespace std;

// O(m.n)
class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        }
        if (grid[i][j] == 1) {
          fresh++;
        }
      }
    }

    if (fresh == 0) {
      return 0;
    }
    if (q.empty()) {
      return -1;
    }

    vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int mins = -1;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : dirs) {
          int r = x + dx;
          int c = y + dy;

          if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
            grid[r][c] = 2;
            fresh--;
            q.push({r, c});
          }
        }
      }
      mins++;
    }
    if (fresh == 0) {
      return mins;
    }
    return -1;
  }
};
