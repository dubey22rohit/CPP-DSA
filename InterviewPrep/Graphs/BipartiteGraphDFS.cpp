#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/is-graph-bipartite/
bool dfs(vector<vector<int>>& graph, int color, int node, vector<int>& colors) {
  colors[node] = color;

  for (auto it : graph[node]) {
    if (colors[it] == -1) {
      if (!dfs(graph, !color, it, colors)) {
        return false;
      }
    } else if (colors[it] == color) {
      return false;
    }
  }
  return true;
}

bool isBipartite(vector<vector<int>>& graph) {
  int v = graph.size();
  vector<int> colors(v, -1);

  for (int i = 0; i < v; i++) {
    if (colors[i] == -1) {
      if (!dfs(graph, 0, i, colors)) {
        return false;
      };
    }
  }
  return true;
}

void addEdge(vector<vector<int>> adj, int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {
  // V = 4, E = 4
  vector<vector<int>> adj(4, vector<int>(4));

  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 1);

  bool ans = isBipartite(adj);
  cout << ans;

  return 0;
}