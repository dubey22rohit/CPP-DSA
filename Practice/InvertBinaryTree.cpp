#include <iostream>

#include "TreeNode.h"
using namespace std;

TreeNode* invertTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int main() { return 0; }