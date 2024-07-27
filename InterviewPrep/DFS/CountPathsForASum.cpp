#include <iostream>

#include "../Helpers/TreeNode.cpp"
using namespace std;

// Given a binary tree and a number ‘S’, find all paths in the tree such that
// the sum of all the node values of each path equals ‘S’. Please note that the
// paths can start or end at any node but all paths must follow direction from
// parent to child (top to bottom).

int countPathsHelper(TreeNode* root, int S, int totalPaths) {
  if (!root) {
    return 0;
  }
  if (root->val = S) {
    totalPaths++;
  }

  return countPathsHelper(root, S - root->val, totalPaths);
}
int countPaths(TreeNode* root, int S) {
  if (!root) {
    return -1;
  }
  return countPathsHelper(root, S, 0);
}
int main() { return 0; }