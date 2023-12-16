#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<char>> grid, int sv, int v, vector<bool> &visited,
        int count) {
  visited[sv] = true;
  for (int i = 0; i < v; i++) {
    if (grid[sv][i] == '1') {
      count++;
      if (i != sv && !visited[i]) {
        dfs(grid, i, v, visited, count);
      }
    }
  }
  return count;
}

int numIslands(vector<vector<char>> grid) {
  vector<bool> visited(grid.size() + 1);
  int ans = dfs(grid, 0, grid.size(), visited, 0);
  return ans;
}

int main() {
  vector<vector<char>> grid{
      {'1', '1', '1', '1', '0'},
      {'1', '1', '0', '1', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '0', '0', '0'},
  };
  int ans = numIslands(grid);
  cout << ans;

  return 0;
}
