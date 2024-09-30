#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

// Given a binary tree, find the length of its diameter. The diameter of a tree
// is the number of nodes on the longest path between any two leaf nodes. The
// diameter of a tree may or may not pass through the root.

/**
 * Finds the height and diameter of a binary tree.
 *
 * @param root The root node of the binary tree.
 * @return A pair containing the height and diameter of the tree.
 * The height is the number of nodes along the longest path from the root
 * to any leaf node. The diameter is the number of nodes on the longest
 * path between any two leaf nodes.
 */
pair<int, int> heightDiameter(TreeNode* root) {
  // Base case: If the root is null, return (0, 0) for height and diameter.
  if (root == nullptr) {
    return make_pair(0, 0);
  }

  // Recursively find the height and diameter of the left and right subtrees.
  pair<int, int> leftAns = heightDiameter(root->left);
  pair<int, int> rightAns = heightDiameter(root->right);

  // Extract the height and diameter values from the subtree answers.
  int lh = leftAns.first;
  int ld = leftAns.second;

  int rh = rightAns.first;
  int rd = rightAns.second;

  // Calculate the height and diameter of the current node.
  int height =
      1 + max(lh, rh);  // Height is 1 plus the max height of the subtrees
  int diameter = max(
      lh + rh,
      max(ld, rd));  // Diameter is the max of the sum of heights of subtrees,
                     // or the max of the diameters of the subtrees

  // Return the height and diameter of the current node.
  return make_pair(height, diameter);
}

/**
 * Finds the diameter of a binary tree.
 *
 * @param root The root node of the binary tree.
 * @return The diameter of the binary tree. The diameter is the number of nodes
 * on the longest path between any two leaf nodes.
 */
int findDiameter(TreeNode* root) {
  // Call the heightDiameter function to get the height and diameter of the
  // tree. The height is the number of nodes along the longest path from the
  // root to any leaf node, and the diameter is the number of nodes on the
  // longest path between any two leaf nodes.
  int treeDiameter = heightDiameter(root).second;

  // The diameter of the tree is 1 plus the diameter of the subtree.
  // So, return 1 plus the diameter of the subtree.
  return 1 + treeDiameter;
}

int main() {
  TreeNode* root = createTree();
  printTree(root);

  cout << findDiameter(root);

  return 0;
}