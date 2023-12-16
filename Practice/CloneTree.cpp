#include <iostream>

#include "TreeNode.h"
using namespace std;

// Given the root node of a tree root, return a clone of the root node. When you
// modify the cloned tree, the original tree should not be affected.
// SPC: O(n)
// TC: O(n)

TreeNode* cloneTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }

    TreeNode* clone = new TreeNode(root->val);
    clone->left = cloneTree(root->left);
    clone->right = cloneTree(root->right);

    return clone;
}

int main() { return 0; }