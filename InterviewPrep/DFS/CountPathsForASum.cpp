#include <iostream>

#include "../Helpers/TreeNode.cpp"
using namespace std;

// Given a binary tree and a number ‘S’, find all paths in the tree such that
// the sum of all the node values of each path equals ‘S’. Please note that the
// paths can start or end at any node but all paths must follow direction from
// parent to child (top to bottom).

/**
 * Recursive helper function to count the number of paths in a binary tree
 * such that the sum of the node values of each path equals a given target sum.
 *
 * @param root The root of the binary tree.
 * @param S The target sum of each path.
 * @param currentPath The current path being explored.
 *
 * @return The number of paths that sum to the target sum.
 */
int countPathsHelper(TreeNode* root, int S, vector<int>& currentPath) {
  // Base case: empty tree
  if (!root) {
    return 0;
  }

  // Add the value of the current node to the current path
  currentPath.push_back(root->val);

  // Initialize the count of paths and the current path sum
  int pathCount = 0, pathSum = 0;

  // Iterate through the current path in reverse order
  for (vector<int>::reverse_iterator itr = currentPath.rbegin();
       itr != currentPath.rend(); ++itr) {
    // Add the value of the current node to the current path sum
    pathSum += *itr;

    // If the current path sum equals the target sum, increment the path count
    if (pathSum == S) {
      pathCount++;
    }
  }

  // Recursively count the paths in the left and right subtrees
  pathCount += countPathsHelper(root->left, S, currentPath);
  pathCount += countPathsHelper(root->right, S, currentPath);

  // Remove the value of the current node from the current path
  // need to remove the current node while going up the recursive call stack.
  currentPath.pop_back();

  return pathCount;
}
int countPaths(TreeNode* root, int S) {
  vector<int> currentPath;
  return countPathsHelper(root, S, currentPath);
}
int main() {
  TreeNode* root = createTree();
  printTree(root);
  cout << countPaths(root, 12);

  return 0;
}