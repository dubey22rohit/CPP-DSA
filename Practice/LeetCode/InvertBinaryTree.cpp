#include <iostream>
using namespace std;

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return root;
    }

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int main() { return 0; }