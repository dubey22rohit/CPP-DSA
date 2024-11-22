#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

// https://www.geeksforgeeks.org/problems/children-sum-parent/1
int isSumProperty(TreeNode *root) {
  if (!root || (!root->left && !root->right)) {
    return 1;
  }
  int childSum = 0;
  if (root->left) {
    childSum += root->left->val;
  }
  if (root->right) {
    childSum += root->right->val;
  }
  if (root->val == childSum) {
    int lans = isSumProperty(root->left);
    int rans = isSumProperty(root->right);
    if (lans == 1 && rans == 1) {
      return 1;
    }
  }
  return 0;
}

int main() { return 0; }