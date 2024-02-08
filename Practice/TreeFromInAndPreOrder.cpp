#include "TreeNode.h"
#include <iostream>
#include <vector>
using namespace std;

TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &index, int i,
                int j) {
  if (i > j) {
    return NULL;
  }

  TreeNode *root = new TreeNode(preorder[index]);

  int split = 0;
  for (int i = 0; i < inorder.size(); ++i) {
    if (preorder[index] == inorder[i]) {
      split = i;
      break;
    }
  }
  index++;

  root->left = build(preorder, inorder, index, i, split - 1);
  root->right = build(preorder, inorder, index, split + 1, j);

  return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  int index = 0;
  return build(preorder, inorder, index, 0, preorder.size() - 1);
}

int main() {
  vector<int> preorder;
  vector<int> inorder;

  int pre, in;
  cin >> pre >> in;

  int a;
  for (int i = 0; i < pre; ++i) {
    cin >> a;
    preorder.push_back(a);
  }

  for (int i = 0; i < in; ++i) {
    cin >> a;
    inorder.push_back(a);
  }

  TreeNode *root = buildTree(preorder, inorder);
  printTree(root);

  return 0;
}
