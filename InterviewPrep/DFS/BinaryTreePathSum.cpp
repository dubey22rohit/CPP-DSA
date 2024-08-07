#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

// Given a binary tree and a number ‘S’, find if the tree has a path from
// root-to-leaf such that the sum of all the node values of that path equals
// ‘S’.

/**
 * Checks if a binary tree has a root-to-leaf path such that the sum of all node
 * values of that path equals 'sum'.
 *
 * @param root The root of the binary tree.
 * @param sum The target sum.
 * @return true if the tree has a path with the target sum, false otherwise.
 */
bool hasPath(TreeNode* root, int sum) {
  // Base case: empty tree
  if (!root) {
    return false;
  }

  // Base case: leaf node
  if (root->val == sum && !root->left && !root->right) {
    return true;
  }

  // Recursive case: check left and right subtrees
  return hasPath(root->left, sum - root->val) ||
         hasPath(root->right, sum - root->val);
}

int main() {
  TreeNode* root = createTree();
  printTree(root);

  cout << "Tree has path: " << hasPath(root, 23) << endl;
  cout << "Tree has path: " << hasPath(root, 16) << endl;

  return 0;
}