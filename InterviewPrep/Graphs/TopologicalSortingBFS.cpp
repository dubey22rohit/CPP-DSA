#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> findTopoSortBFS(vector<vector<int>> graph) {
  int v = graph.size();
  vector<int> indegree(v, 0);
  for (int i = 0; i < v; i++) {
    for (auto it : graph[i]) {
      indegree[it]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < v; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> result;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    result.push_back(node);

    for (auto it : graph[node]) {
      indegree[it]--;
      if (indegree[it] == 0) {
        q.push(it);
      }
    }
  }
  return result;
}

int main() {
  vector<vector<int>> graph(6);

  graph[5].push_back(2);
  graph[5].push_back(0);
  graph[4].push_back(0);
  graph[4].push_back(1);
  graph[2].push_back(3);
  graph[3].push_back(1);

  vector<int> result = findTopoSortBFS(graph);
  for (auto n : result) {
    cout << n << ", ";
  }
  return 0;
}