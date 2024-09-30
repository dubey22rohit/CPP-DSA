#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

// This only works if the requirement is that the path is starting from root.
// In the original question it says that the path can start from anywhere and
// end anywhere given that it flows from parent to child. For the actual answer
// see CountParthsForASum.cpp in this folder.

void countPathsHelper(TreeNode* root, int S, int& totalPaths) {
  if (!root) {
    return;
  }
  if (root->val == S) {
    totalPaths++;
    return;
  }
  countPathsHelper(root->left, S - root->val, totalPaths);
  countPathsHelper(root->right, S - root->val, totalPaths);
}

int countPaths(TreeNode* root, int S) {
  int totalPaths = 0;
  countPathsHelper(root, S, totalPaths);
  return totalPaths;
}

int main() {
  TreeNode* root = createTree();
  printTree(root);
  cout << countPaths(root, 14);

  return 0;
}