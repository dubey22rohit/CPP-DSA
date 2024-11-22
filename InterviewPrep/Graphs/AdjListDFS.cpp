#include <iostream>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
void dfs(vector<vector<int>>& adj, int sv, vector<int>& visited,
         vector<int>& result) {
  result.push_back(sv);
  visited[sv] = 1;
  for (auto it : adj[sv]) {
    if (!visited[it]) {
      dfs(adj, it, visited, result);
    }
  }
}

vector<int> dfsOfGraph(vector<vector<int>>& adj) {
  int v = adj.size();
  vector<int> visited(v);
  vector<int> result;
  dfs(adj, 0, visited, result);
  return result;
}

int main() {
  vector<vector<int>> adj{{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
  vector<int> dfsResult = dfsOfGraph(adj);
  for (auto it : dfsResult) {
    cout << it << ", ";
  }
  return 0;
}