#include <iostream>

#include "../Helpers/TreeNode.cpp"
using namespace std;

// Find the path with the maximum sum in a given binary tree. Write a function
// that returns the maximum sum. A path can be defined as a sequence of nodes
// between any two nodes and doesn’t necessarily pass through the root.

/**
 * Recursive helper function to find the maximum sum path in a binary tree.
 *
 * @param root The root of the binary tree.
 * @param globalMax A reference to the maximum sum found so far.
 * @return The maximum sum path from the root to a leaf node.
 */
int maxPathSumHelper(TreeNode* root, int& globalMax) {
  // Base case: empty tree
  if (root == nullptr) {
    return 0;
  }

  // Recursively find the maximum sum path from the left and right subtrees
  // Elimating any negative sums.
  int maxPathSumFromLeft = max(maxPathSumHelper(root->left, globalMax), 0);
  int maxPathSumFromRight = max(maxPathSumHelper(root->right, globalMax), 0);

  // Calculate the maximum sum path from the current node to a leaf node
  // maximum path sum at the current node will be equal to the sum from the left
  // subtree + sum from the right subtree + val of current node
  int localMaxSum = maxPathSumFromLeft + maxPathSumFromRight + root->val;

  // Update the global maximum if the current path sum is greater
  globalMax = max(globalMax, localMaxSum);

  // Return the maximum sum path from the current node to a leaf node
  // maximum sum of any path from the current node will be equal to the
  // maximum of the sums from left or right subtrees plus the value of the
  // current node
  return max(maxPathSumFromLeft, maxPathSumFromRight) + root->val;
}

int maxPathSum(TreeNode* root) {
  int globalMaxSum = numeric_limits<int>::min();
  maxPathSumHelper(root, globalMaxSum);
  return globalMaxSum;
}

int main() {
  TreeNode* root = createTree();
  printTree(root);

  cout << maxPathSum(root);

  return 0;
}