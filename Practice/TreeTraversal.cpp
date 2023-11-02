#include <iostream>

#include "TreeNode.h"
using namespace std;

// Use preorder when you want to act on all the parent nodes of a tree before
// the children nodes.
void preorder(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    TreeNode* root = createTree();
    printTree(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);
    return 0;
}