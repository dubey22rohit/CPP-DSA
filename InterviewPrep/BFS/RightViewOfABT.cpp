#include <iostream>
#include <queue>
#include <vector>

#include "../Helpers/TreeNode.h"

using namespace std;

vector<TreeNode*> traverse(TreeNode* root) {
  vector<TreeNode*> result;
  if (!root) {
    return result;
  }

  queue<TreeNode*> pn;
  pn.push(root);
  result.push_back(root);

  while (!pn.empty()) {
    int levelSize = pn.size();
    TreeNode* lastNode = nullptr;
    for (int i = 0; i < levelSize; i++) {
      TreeNode* f = pn.front();
      pn.pop();

      // Another way:
      // if (i == levelSize - 1) {
      //   result.push_back(f);
      // }

      if (f->left) {
        lastNode = f->left;
        pn.push(f->left);
      }

      if (f->right) {
        lastNode = f->right;
        pn.push(f->right);
      }
    }
    if (lastNode) {
      result.push_back(lastNode);
    }
  }

  return result;
}

int main() {
  TreeNode* root = createTree();
  vector<TreeNode*> ans = traverse(root);
  cout << "\nANS:\n";
  for (TreeNode* a : ans) {
    cout << a->val << ", ";
  }
  return 0;
}