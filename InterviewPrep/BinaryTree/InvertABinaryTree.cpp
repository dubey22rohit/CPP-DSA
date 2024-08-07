#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

/**
 * @brief Inverts a binary tree recursively
 *
 * @param root The root node of the binary tree
 * @return TreeNode* The inverted binary tree
 *
 * @details This function takes a binary tree as input and recursively inverts
 * the left and right subtrees of each node. It swaps the left and right
 * pointers of each node and returns the root of the inverted binary tree.
 */
TreeNode* invertTree(TreeNode* root) {
  // Base case: if root is null, return null
  if (!root) {
    return nullptr;
  }

  // Invert the left and right subtrees
  TreeNode* temp = root->left;
  root->left = root->right;
  root->right = temp;

  // Recursively invert the left and right subtrees
  invertTree(root->left);
  invertTree(root->right);

  // Return the inverted binary tree
  return root;
}

int main() {
  TreeNode* root = createTree();
  printTree(root);
  invertTree(root);
  cout << "\nAfter inverting:\n";
  printTree(root);
  return 0;
}