#include <iostream>

#include "../Helpers/TreeNode.cpp"
using namespace std;

// Given a binary tree where each node can only have a digit (0-9) value, each
// root-to-leaf path will represent a number. Find the total sum of all the
// numbers represented by all paths.

/**
 * Helper function to find the sum of all path numbers in a binary tree.
 *
 * @param root The root of the binary tree.
 * @param pathSum The sum of the path numbers so far.
 * @return The sum of all path numbers in the binary tree.
 */
int findSumOfPathNumbersHelper(TreeNode* root, int pathSum) {
  // Base case: empty tree
  if (!root) {
    return 0;
  }

  // Update the path sum by multiplying the existing path sum by 10 and adding
  // the value of the current node
  pathSum = 10 * pathSum + root->val;

  // Base case: leaf node
  if (!root->left && !root->right) {
    return pathSum;
  }

  // Recursive case: find the sum of path numbers in the left and right subtrees
  return findSumOfPathNumbersHelper(root->left, pathSum) +
         findSumOfPathNumbersHelper(root->right, pathSum);
}

/**
 * Finds the sum of all path numbers in a binary tree.
 *
 * @param root The root of the binary tree.
 * @return The sum of all path numbers in the binary tree.
 */
int findSumOfPathNumbers(TreeNode* root) {
  return findSumOfPathNumbersHelper(root, 0);
}

int main() {
  TreeNode* root = createTree();
  printTree(root);

  int result = findSumOfPathNumbers(root);

  cout << "Result: " << result;

  return 0;
}