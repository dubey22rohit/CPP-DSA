#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(vector<vector<bool>>& graph, int sv, vector<int>& result, int v,
               vector<bool>& visited) {
  result.push_back(sv);
  visited[sv] = true;
  for (int i = 0; i < v; i++) {
    if (graph[sv][i] && i != sv && !visited[i]) {
      dfsHelper(graph, i, result, v, visited);
    }
  }
}

vector<int> DFS(vector<vector<bool>>& graph) {
  int v = graph.size();
  vector<bool> visited(v);
  vector<int> result;
  for (int i = 0; i < v; i++) {
    if (!visited[i]) {
      dfsHelper(graph, i, result, v, visited);
    }
  }
  return result;
}

int main() {
  int v, e;
  cin >> v >> e;

  vector<vector<bool>> graph(v, vector<bool>(v));

  int a, b;
  for (int i = 0; i < e; i++) {
    cin >> a >> b;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  vector<int> dfsResult = DFS(graph);
  for (auto n : dfsResult) {
    cout << n << ", ";
  }

  return 0;
}