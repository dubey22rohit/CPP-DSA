#include <iostream>

#include "TreeNode.h"
using namespace std;

// TC: O(logn)(height of the tree)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (!root) {
    return nullptr;
  }
  if (p->val > root->val && q->val > root->val) {
    return lowestCommonAncestor(root->right, p, q);
  } else if (p->val < root->val && q->val < root->val) {
    return lowestCommonAncestor(root->left, p, q);
  } else {
    return root;
  }
}

int main() { return 0; }
