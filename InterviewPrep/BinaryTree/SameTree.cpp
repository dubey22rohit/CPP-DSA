#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

// https://leetcode.com/problems/maximum-depth-of-binary-tree/

/**
 * Checks if two binary trees are identical.
 *
 * @param p pointer to the root node of the first binary tree
 * @param q pointer to the root node of the second binary tree
 *
 * @return true if the trees are identical, false otherwise
 *
 * The function checks if the trees rooted at p and q are identical.
 * It first checks if both trees are null. If either tree is null,
 * it returns true if both are null, and false otherwise. If both
 * trees are not null, it checks if their values are equal. If their
 * values are not equal, it returns false. Otherwise, it recursively
 * checks if the left subtrees and right subtrees of p and q are
 * identical. If they are, it returns true. Otherwise, it returns false.
 */
bool isSameTree(TreeNode* p, TreeNode* q) {
  // If both trees are null, they are identical
  if (!p || !q) {
    return p == q;
  }

  // If the values of the trees are not equal, they are not identical
  if (p->val != q->val) {
    return false;
  }

  // If the left subtrees, right subtrees, or both are not identical,
  // the trees are not identical
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
int main() {
  TreeNode* p = createTree();
  TreeNode* q = createTree();
  cout << isSameTree(p, q);
  return 0;
}