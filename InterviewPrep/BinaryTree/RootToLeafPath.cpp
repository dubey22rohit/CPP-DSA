#include <iostream>
#include <vector>

#include "../Helpers/TreeNode.h"
using namespace std;

// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1
void dfs(TreeNode* root, vector<int> curr, vector<vector<int>>& result) {
  curr.push_back(root->val);
  if (!root->left && !root->right) {
    result.push_back(curr);
    return;
  }
  if (root->left) {
    dfs(root->left, curr, result);
  }
  if (root->right) {
    dfs(root->right, curr, result);
  }
  curr.pop_back();
}
vector<vector<int>> Paths(TreeNode* root) {
  vector<vector<int>> result;
  vector<int> curr;
  dfs(root, curr, result);
  return result;
}

int main() {
  TreeNode* root = createTree();
  vector<vector<int>> paths = Paths(root);
  return 0;
}