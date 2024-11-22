#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// USING BFS
bool detectCycleBFS(vector<vector<bool>>& graph) {
  int V = graph.size();
  vector<int> parent(V, -1);  // To store parent of each node
  vector<bool> visited(V, false);

  queue<int> pv;
  pv.push(0);
  visited[0] = true;

  while (!pv.empty()) {
    int cv = pv.front();
    pv.pop();

    for (int i = 0; i < V; i++) {
      if (graph[cv][i] && !visited[i]) {
        pv.push(i);
        visited[i] = true;
        parent[i] = cv;
      } else if (graph[cv][i] && parent[cv] != i) {
        return true;
      }
    }
  }

  return false;
}

bool detectCycleDFSHelper(vector<vector<bool>>& graph, int sv, int parentNode,
                          vector<bool>& visited) {
  if (visited[sv]) {
    return true;
  }
  visited[sv] = true;
  for (int i = 0; i < graph.size(); i++) {
    if (!visited[i] && i != sv && graph[sv][i]) {
      if (detectCycleDFSHelper(graph, i, sv, visited)) {
        return true;
      }
    } else if (i != parentNode && graph[sv][i]) {
      return true;
    }
  }
  return false;
}
// USING DFS
bool detectCycleDFS(vector<vector<bool>>& graph) {
  int v = graph.size();
  vector<bool> visited(v);
  return detectCycleDFSHelper(graph, 0, -1, visited);
}

int main() {
  int v, e;
  cin >> v >> e;

  vector<vector<bool>> graph(v, vector<bool>(v));

  int a, b;
  for (int i = 0; i < e; i++) {
    cin >> a >> b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }

  bool detectBFS = detectCycleBFS(graph);
  cout << detectBFS << endl;

  bool detectDFS = detectCycleDFS(graph);
  cout << detectDFS << endl;

  return 0;
}