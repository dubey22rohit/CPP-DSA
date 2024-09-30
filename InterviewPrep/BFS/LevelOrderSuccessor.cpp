#include <iostream>
#include <queue>

#include "../Helpers/TreeNode.h"
using namespace std;

TreeNode* findSuccessor(TreeNode* root, int key) {
  if (!root) {
    return nullptr;
  }

  queue<TreeNode*> pn;
  pn.push(root);

  while (!pn.empty()) {
    TreeNode* f = pn.front();
    pn.pop();

    if (f->left) {
      pn.push(f->left);
    }

    if (f->right) {
      pn.push(f->right);
    }

    if (f->val == key) {
      break;
    }
  }
  return pn.front();
}

int main() {
  TreeNode* root = createTree();
  TreeNode* successor = findSuccessor(root, 9);
  cout << successor->val;
  return 0;
}