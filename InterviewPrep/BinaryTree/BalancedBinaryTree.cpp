#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

// https://leetcode.com/problems/balanced-binary-tree/

/**
 * Calculates the height of a binary tree.
 *
 * @param root The root node of the binary tree.
 * @return The height of the binary tree. If the root is null, returns 0.
 * The height is the number of nodes in the longest downward path from the root.
 */
int height(TreeNode* root) {
  // Base case: If the root is null, return 0.
  if (!root) {
    return 0;
  }

  // Recursive case: Calculate the height of the left and right subtrees,
  // and return 1 plus the maximum of the two heights.
  return 1 + max(height(root->left), height(root->right));
}

/**
 * Checks if a binary tree is balanced.
 *
 * @param root The root node of the binary tree.
 * @return True if the binary tree is balanced, false otherwise.
 * A binary tree is balanced if the height of its left and right subtrees
 * differ by at most 1.
 */
bool isBalanced(TreeNode* root) {
  // Base case: If the root is null, the tree is balanced.
  if (!root) {
    return true;
  }

  // Calculate the height of the left and right subtrees.
  int lh = height(root->left);
  int rh = height(root->right);

  // Check if the difference in height between the left and right subtrees
  // is greater than 1, indicating an unbalanced tree.
  if (abs(lh - rh) > 1) {
    return false;
  }

  // Recursively check if the left and right subtrees are balanced.
  return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
  TreeNode* root = createTree();
  cout << isBalanced(root);
  return 0;
}