#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
  int v = adj.size();
  vector<int> visited(v);
  visited[0] = 1;
  queue<int> pv;
  pv.push(0);
  vector<int> result;
  while (!pv.empty()) {
    int cv = pv.front();
    pv.pop();
    result.push_back(cv);
    for (auto it : adj[cv]) {
      if (!visited[it]) {
        pv.push(it);
        visited[it] = 1;
      }
    }
  }
  return result;
}

int main() {
  vector<vector<int>> adj{{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
  vector<int> bfsResult = bfsOfGraph(adj);
  for (auto it : bfsResult) {
    cout << it << ", ";
  }
  return 0;
}