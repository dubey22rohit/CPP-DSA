#include <iostream>

#include "TreeNode.h"
using namespace std;

int height(TreeNode* root) {
    if (!root) {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

int main() {
    TreeNode* root = createTree();
    printTree(root);

    int h = height(root);
    cout << "\nheight: " << h;

    return 0;
}