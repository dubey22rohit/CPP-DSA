#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

// https://www.geeksforgeeks.org/problems/mirror-tree/1
// Both the solutions mentioned below work!
void mirror(TreeNode* node) {
  if (!node) {
    return;
  }
  mirror(node->left);
  mirror(node->right);
  TreeNode* temp = node->left;
  node->left = node->right;
  node->right = temp;
}

void mirror2(TreeNode* node) {
  if (!node) {
    return;
  }

  TreeNode* temp = node->left;
  node->left = node->right;
  node->right = temp;

  mirror(node->left);
  mirror(node->right);
}

int main() { return 0; }