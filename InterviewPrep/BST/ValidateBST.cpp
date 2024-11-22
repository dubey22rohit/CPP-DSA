#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

// https://leetcode.com/problems/validate-binary-search-tree/
bool isValidBSTHelper(TreeNode* root, long long int minVal,
                      long long int maxVal) {
  if (!root) {
    return true;
  }
  if (root->val <= minVal || root->val >= maxVal) {
    return false;
  }
  return isValidBSTHelper(root->left, minVal, root->val) &&
         isValidBSTHelper(root->right, root->val, maxVal);
}
bool isValidBST(TreeNode* root) {
  long long int min = -1000000000000, max = 1000000000000;
  return isValidBSTHelper(root, min, max);
}

int main() { return 0; }