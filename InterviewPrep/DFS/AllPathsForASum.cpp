#include <iostream>
#include <vector>

#include "../Helpers/TreeNode.cpp"
using namespace std;

// Given a binary tree and a number ‘S’, find all paths from root-to-leaf such
// that the sum of all the node values of each path equals ‘S’.

/**
 * Given a binary tree and a number 'S', find all paths from root-to-leaf such
 * that the sum of all the node values of each path equals 'S'.
 *
 * @param root The root of the binary tree.
 * @param sum The target sum of each path.
 * @param currPath The current path being explored.
 * @param allPaths All paths found so far.
 */
void findAllPathsHelper(TreeNode* root, int sum, vector<int>& currPath,
                        vector<vector<int>>& allPaths) {
  if (!root) {
    // Base case: empty tree
    return;
  }

  currPath.push_back(root->val);

  if (root->val == sum && !root->left && !root->right) {
    // Found a valid path
    allPaths.push_back(vector<int>(currPath));
  } else {
    // Explore left and right subtrees
    findAllPathsHelper(root->left, sum - root->val, currPath, allPaths);
    findAllPathsHelper(root->right, sum - root->val, currPath, allPaths);
  }

  currPath.pop_back();
  // Backtrack and remove the current path
}

/**
 * Finds all paths from the root of a binary tree to its leaves such that the
 * sum of the values of the nodes in each path is equal to a given target sum.
 *
 * @param root The root of the binary tree.
 * @param sum The target sum of each path.
 *
 * @return A vector of vectors, where each inner vector represents a path from
 *         the root to a leaf. Each inner vector contains the values of the
 *         nodes in the path.
 */
vector<vector<int>> findPaths(TreeNode* root, int sum) {
  // Vector to store all paths found
  vector<vector<int>> allPaths;

  // Vector to store the current path being explored
  vector<int> currPath;

  // Helper function to perform the DFS
  findAllPathsHelper(root, sum, currPath, allPaths);

  // Return the paths found
  return allPaths;
}

int main() {
  TreeNode* root = createTree();
  printTree(root);

  int sum;
  cin >> sum;
  vector<vector<int>> result = findPaths(root, sum);
  printf("Tree paths with sum %d, size: %lu\n", sum, result.size());
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "\n";
  }
  return 0;
}