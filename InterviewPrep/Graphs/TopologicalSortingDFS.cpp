#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Only possible for DAG(Directed  Acyclic Graph)
// TC: O(V + E)
// SC: O(N) + O(N)(Stack we're using)
// AuxSC: O(N)

void findTopoSortHelper(vector<vector<int>> graph, int node,
                        vector<int>& visited, stack<int>& st) {
  visited[node] = 1;
  for (auto n : graph[node]) {
    if (!visited[n]) {
      findTopoSortHelper(graph, n, visited, st);
    }
  }
  st.push(node);
}

vector<int> findTopoSort(vector<vector<int>> graph) {
  stack<int> st;
  vector<int> visited(graph.size(), 0);
  for (int i = 0; i < graph.size(); i++) {
    if (!visited[i]) {
      findTopoSortHelper(graph, i, visited, st);
    }
  }
  vector<int> result;
  while (!st.empty()) {
    result.push_back(st.top());
    st.pop();
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

  vector<int> result = findTopoSort(graph);
  for (auto n : result) {
    cout << n << ", ";
  }
  return 0;
}