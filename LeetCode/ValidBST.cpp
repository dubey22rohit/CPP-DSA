#include <iostream>

#include "TreeNode.h"
using namespace std;

bool isValidBST(TreeNode* root, int min, int max) {
    if (root == nullptr) {
        return true;
        if (root->val < min || root->val > max) {
            return false;
        }
        bool leftAns = isValidBST(root->left, min, root->val);
        bool rightAns = isValidBST(root->right, root->val, max);

        return leftAns && rightAns;
    }
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, INT32_MIN, INT32_MAX);
}

int main() {
    TreeNode* root = createTree();
    printTree(root);
    cout << isValidBST(root);
    return 0;
}