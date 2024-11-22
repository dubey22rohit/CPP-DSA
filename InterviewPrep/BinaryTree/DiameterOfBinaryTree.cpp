#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

// https://leetcode.com/problems/diameter-of-binary-tree/
/**
 * Calculates the height and diameter of a binary tree.
 *
 * @param root The root node of the binary tree.
 * @return A pair containing the height and diameter of the tree.
 * The height is the number of nodes along the longest path from the root
 * to any leaf node. The diameter is the number of nodes on the longest
 * path between any two leaf nodes.
 */
pair<int, int> heightDiameter(TreeNode* root) {
  // Base case: If the root is null, return (0, 0) for height and diameter.
  if (!root) {
    return make_pair(0, 0);
  }

  // Recursively find the height and diameter of the left and right subtrees.
  pair<int, int> leftAns = heightDiameter(root->left);
  pair<int, int> rightAns = heightDiameter(root->right);

  // Extract the height and diameter values from the subtree answers.
  int lh = leftAns.first, ld = leftAns.second;
  int rh = rightAns.first, rd = rightAns.second;

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

int diameterOfBinaryTree(TreeNode* root) { return heightDiameter(root).second; }

int main() {
  TreeNode* root = createTree();
  printTree(root);
  int d = diameterOfBinaryTree(root);
  cout << "\nDiameter: " << d;
  return 0;
}