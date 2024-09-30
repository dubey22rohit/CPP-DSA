#include <deque>
#include <iostream>
#include <queue>

#include "../Helpers/TreeNode.h"
using namespace std;

vector<vector<int>> traverse(TreeNode* root) {
  if (!root) {
    return {};
  }

  vector<vector<int>> result;

  queue<TreeNode*> pn;
  pn.push(root);

  while (!pn.empty()) {
    int levelsize = pn.size();
    vector<int> curr;
    for (int i = 0; i < levelsize; i++) {
      TreeNode* f = pn.front();
      pn.pop();

      curr.push_back(f->val);

      if (f->left) {
        pn.push(f->left);
      }

      if (f->right) {
        pn.push(f->right);
      }
    }
    result.push_back(curr);
  }
  reverse(result.begin(), result.end());

  return result;
}

deque<vector<int>> traverse2(TreeNode* root) {
  deque<vector<int>> result = deque<vector<int>>();
  if (!root) {
    return result;
  }

  queue<TreeNode*> pn;
  pn.push(root);

  while (!pn.empty()) {
    int levelsize = pn.size();
    vector<int> curr;
    for (int i = 0; i < levelsize; i++) {
      TreeNode* f = pn.front();
      pn.pop();

      curr.push_back(f->val);

      if (f->left) {
        pn.push(f->left);
      }

      if (f->right) {
        pn.push(f->right);
      }
    }
    result.push_front(curr);
  }
  return result;
}

int main() {
  TreeNode* root = createTree();
  vector<vector<int>> ans = traverse(root);
  cout << "\nANS:\n";
  for (auto a : ans) {
    for (auto n : a) {
      cout << n << ", ";
    }
    cout << "\n";
  }
  deque<vector<int>> ans2 = traverse2(root);

  cout << "\nANS2:\n";
  for (auto a : ans2) {
    for (auto n : a) {
      cout << n << ", ";
    }
    cout << "\n";
  }
  return 0;
}