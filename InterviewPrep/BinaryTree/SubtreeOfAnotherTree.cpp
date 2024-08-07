#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

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

/**
 * Checks if a binary tree is a subtree of another binary tree.
 *
 * @param root pointer to the root node of the binary tree to search in
 * @param subRoot pointer to the root node of the binary tree to search for
 *
 * @return true if subRoot is a subtree of root, false otherwise
 *
 * The function checks if the binary tree rooted at subRoot is a subtree
 * of the binary tree rooted at root. It first checks if either tree is
 * null. If either tree is null, it returns true if both are null, and
 * false otherwise. If both trees are not null, it checks if they are
 * identical using the isSameTree function. If they are identical, it
 * returns true. Otherwise, it recursively checks if subRoot is a subtree
 * of the left subtree of root, and if it is not, it recursively checks if
 * subRoot is a subtree of the right subtree of root. If subRoot is a
 * subtree of either the left or right subtree, it returns true.
 * Otherwise, it returns false.
 */
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  // If either tree is null, they are not identical
  if (!root || !subRoot) {
    return root == subRoot;
  }

  // If the trees are identical, subRoot is a subtree of root
  if (isSameTree(root, subRoot)) {
    return true;
  }

  // Recursively check if subRoot is a subtree of the left or right subtree
  return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
  TreeNode* root = createTree();
  printTree(root);
  TreeNode* subRoot = createTree();
  printTree(subRoot);

  cout << isSubtree(root, subRoot);

  return 0;
}