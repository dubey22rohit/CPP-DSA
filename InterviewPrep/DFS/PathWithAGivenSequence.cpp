#include <iostream>
#include <vector>

#include "../Helpers/TreeNode.h"
using namespace std;

// Given a binary tree and a number sequence, find if the sequence is present as
// a root-to-leaf path in the given tree.

bool findPathHelper(TreeNode* root, const vector<int>& sequence, int index) {
  if (!root) {
    return false;
  }

  if (index >= sequence.size() || root->val != sequence[index]) {
    return false;
  }

  if (root->val == sequence[index] && !root->left && !root->right) {
    return true;
  }

  return findPathHelper(root->left, sequence, index++) ||
         findPathHelper(root->right, sequence, index++);
}

bool findPath(TreeNode* root, const vector<int>& sequence) {
  if (!root) {
    return false;
  }
  return findPathHelper(root, sequence, 0);
}

int main() {
  TreeNode* root = createTree();
  printTree(root);
  cout << "Has Path: " << findPath(root, vector<int>{1, 9, 9});
  return 0;
}