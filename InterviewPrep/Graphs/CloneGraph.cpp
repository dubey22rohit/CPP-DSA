#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// https://leetcode.com/problems/clone-graph/description/

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

Node* bfs(Node* node) {
  if (!node) {
    return nullptr;
  }
  unordered_map<Node*, Node*> hm;
  queue<Node*> q;
  q.push(node);
  hm[node] = new Node(node->val);

  while (!q.empty()) {
    Node* curr = q.front();
    q.pop();

    for (Node* adj : curr->neighbors) {
      if (hm.find(adj) == hm.end()) {
        hm[adj] = new Node(adj->val);
        q.push(adj);
      }
      hm[curr]->neighbors.push_back(hm[adj]);
    }
  }

  return hm[node];
}

Node* dfs(Node* node, unordered_map<Node*, Node*>& hm) {
  if (!node) {
    return nullptr;
  }
  if (hm.count(node)) {
    return hm[node];
  }

  Node* copy = new Node(node->val);
  hm[node] = copy;

  for (Node* adj : node->neighbors) {
    copy->neighbors.push_back(dfs(adj, hm));
  }

  return copy;
}

Node* cloneGraph(Node* node) {
  unordered_map<Node*, Node*> hm;
  return dfs(node, hm);
}

int main() { return 0; }