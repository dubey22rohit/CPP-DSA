#include <iostream>

#include "TreeNode.h"
using namespace std;

bool validBST(TreeNode* root, int minValue, int maxValue) {
    if (!root) {
        return true;
    }

    if (root->data < minValue || root->data >= maxValue) {
        return false;
    }

    bool lans = validBST(root->lchild, minValue, root->data);
    bool rans = validBST(root->rchild, root->data, maxValue);

    return lans && rans;
}

bool validBST(TreeNode* root) { return validBST(root, INT32_MIN, INT32_MAX); }

int main() {
    TreeNode* root = createTree();

    cout << (validBST(root) ? "valid" : "invalid");

    return 0;
}