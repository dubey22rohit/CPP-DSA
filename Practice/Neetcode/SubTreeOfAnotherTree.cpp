#include <iostream>

#include "TreeNode.h"
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
  if (!p || !q) {
    return p == q;
  }

  if (p->val != q->val) {
    return false;
  }

  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubTree(TreeNode* root, TreeNode* subRoot) {
  if (!root || !subRoot) {
    return root == subRoot;
  }
  if (isSameTree(root, subRoot)) {
    return true;
  }
  return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
}

int main() { return 0; }