#include <iostream>

#include "TreeNode.h"
using namespace std;

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
        return NULL;
    }

    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left && !root->right) {
            return NULL;
        }
        if (root->left) {
            TreeNode* delRoot = root;
            root = root->left;

            return root;
        }
        if (root->right) {
            root->val = root->right->val;
            root->right = NULL;
            return root;
        }
    }
    return root;
}

int main() {
    TreeNode* root = createTree();
    int val;
    cin >> val;

    TreeNode* newRoot = deleteNode(root, val);
    printTree(newRoot);

    return 0;
}