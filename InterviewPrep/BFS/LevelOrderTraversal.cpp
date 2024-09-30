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
    int levelSize = pn.size();
    vector<int> curr;
    for (int i = 0; i < levelSize; i++) {
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
  return 0;
}