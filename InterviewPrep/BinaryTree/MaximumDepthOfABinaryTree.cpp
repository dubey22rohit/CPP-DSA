#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

/**
 * Returns the maximum depth of a binary tree.
 *
 * @param root Pointer to the root of the binary tree.
 * @return The maximum depth of the binary tree.
 *
 * The maximum depth of a binary tree is the number of nodes along the longest
 * path from the root to any leaf node.i.e Height of the tree.
 */
int maxDepth(TreeNode* root) {
  // Base case: If the root is null, the depth is 0.
  if (!root) {
    return 0;
  }

  // Recursively calculate the depth of the left and right subtrees.
  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);

  // Return 1 plus the maximum depth of the subtrees.
  return 1 + max(lh, rh);
}

int main() {
  TreeNode* root = createTree();
  cout << maxDepth(root);
  return 0;
}