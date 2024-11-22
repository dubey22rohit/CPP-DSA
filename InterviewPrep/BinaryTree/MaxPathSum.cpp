#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

// https://leetcode.com/problems/binary-tree-maximum-path-sum/
int dfs(TreeNode* root, vector<int>& result) {
  if (!root) {
    return 0;
  }
  int lm = dfs(root->left, result);
  int rm = dfs(root->right, result);
  lm = max(lm, 0);
  rm = max(rm, 0);

  result[0] = max(result[0], root->val + lm + rm);
  return root->val + max(lm, rm);
}
int maxPathSum(TreeNode* root) {
  if (!root) {
    return 0;
  }
  vector<int> result{root->val};
  dfs(root, result);
  return result[0];
}

int main() { return 0; }