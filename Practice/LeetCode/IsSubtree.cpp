#include <iostream>

#include "TreeNode.h"
using namespace std;

bool isSameTree(TreeNode* root, TreeNode* subRoot) {
    if (!root && !subRoot) {
        return true;
    }

    if (!root || !subRoot) {
        return false;
    }

    if (root->val != subRoot->val) {
        return false;
    }

    return isSameTree(root->left, subRoot->left) &&
           isSameTree(root->right, subRoot->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root || !subRoot) {
        return false;
    }
    if (isSameTree(root, subRoot)) {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    TreeNode* root = createTree();
    TreeNode* subRoot = createTree();

    cout << isSubtree(root, subRoot);
    return 0;
}