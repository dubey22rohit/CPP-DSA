#include <iostream>

#include "TreeNode.h"
using namespace std;

bool ans = true;
int treeHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);

    if (abs(lh - rh) > 1) {
        ans = false;
    }

    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode* root) {
    treeHeight(root);
    return ans;
}

int main() {
    TreeNode* root = createTree();
    printTree(root);
    cout << "\n";
    cout << (isBalanced(root) ? "balanced" : "un-balanced");
    return 0;
}