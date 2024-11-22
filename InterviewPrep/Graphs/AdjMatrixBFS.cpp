#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfsHelper(vector<vector<bool>>& graph, int sv, int v,
               vector<bool>& visited, vector<int>& result) {
  queue<int> pv;
  pv.push(sv);
  visited[sv] = true;
  while (!pv.empty()) {
    int cv = pv.front();
    pv.pop();
    result.push_back(cv);
    for (int i = 0; i < v; i++) {
      if (graph[cv][i] && i != cv && !visited[i]) {
        pv.push(i);
        visited[i] = true;
      }
    }
  }
}

vector<int> BFS(vector<vector<bool>>& graph) {
  int v = graph.size();
  vector<bool> visited(v);
  vector<int> result;
  for (int i = 0; i < v; i++) {
    if (!visited[i]) {
      bfsHelper(graph, i, v, visited, result);
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
    graph[a][b] = 1;
    graph[b][a] = 1;
  }

  vector<int> bfsResult = BFS(graph);
  for (auto it : bfsResult) {
    cout << it << ", ";
  }

  return 0;
}