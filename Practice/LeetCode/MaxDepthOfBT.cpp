#include <iostream>

#include "TreeNode.h"
using namespace std;

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
// Basically the height of the tree

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() { return 0; }