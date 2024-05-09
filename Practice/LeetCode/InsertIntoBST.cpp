#include <iostream>

#include "TreeNode.h"
using namespace std;

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        TreeNode* newRoot = new TreeNode(val);
        return newRoot;
    }
    if (root->val > val) {
        root->left = insertIntoBST(root->left, val);
    }
    if (root->val < val) {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

int main() {
    TreeNode* root = createTree();
    int val;
    cin >> val;

    TreeNode* newRoot = insertIntoBST(root, val);

    printTree(newRoot);

    return 0;
}