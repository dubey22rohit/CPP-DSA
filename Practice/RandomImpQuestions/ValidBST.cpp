#include <iostream>

#include "TreeNode.h"
using namespace std;

// TC: O(N): N = number of nodes
// SC: O(d): d = depth of tree, max amount of callstack we'll use

bool validBSTHelper(TreeNode* root, int minValue, int maxValue) {
    if (root == nullptr) {
        return true;
    }
    if (root->data < minValue || root->data >= maxValue) {
        return false;
    }
    bool leftAns = validBSTHelper(root->lchild, minValue, root->data);
    bool rightAns = validBSTHelper(root->rchild, root->data, maxValue);

    return leftAns && rightAns;
}

bool validBST(TreeNode* root) {
    return validBSTHelper(root, INT32_MIN, INT32_MAX);
}

int main() {
    TreeNode* root = createTree();
    printTree(root);
    cout << endl;
    cout << (validBST(root) ? "valid" : "invalid");
    return 0;
}