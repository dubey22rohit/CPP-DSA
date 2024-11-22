#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

// https://leetcode.com/problems/search-in-a-binary-search-tree/
TreeNode* searchBST(TreeNode* root, int val) {
  if (!root) {
    return nullptr;
  }
  if (root->val < val) {
    return searchBST(root->right, val);
  } else if (root->val > val) {
    return searchBST(root->left, val);
  }
  return root;
}

int main() { return 0; }