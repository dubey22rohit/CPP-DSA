#include <iostream>
#include <vector>

#include "../Helpers/TreeNode.h"
using namespace std;

// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
vector<int> leftView(TreeNode* root) {
  queue<TreeNode*> pn;
  pn.push(root);
  vector<int> result;
  result.push_back(root->val);
  while (!pn.empty()) {
    int levelSize = pn.size();
    TreeNode* lastNode = nullptr;
    for (int i = 0; i < levelSize; i++) {
      TreeNode* f = pn.front();
      pn.pop();

      if (f->right) {
        lastNode = f->right;
        pn.push(f->right);
      }

      if (f->left) {
        lastNode = f->left;
        pn.push(f->left);
      }
    }
    if (lastNode) {
      result.push_back(lastNode->val);
    }
  }
  return result;
}

int main() { return 0; }