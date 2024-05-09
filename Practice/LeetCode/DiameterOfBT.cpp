#include <iostream>

#include "TreeNode.h"

using namespace std;

// https://leetcode.com/problems/diameter-of-binary-tree/description/

int heightOfBT(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + max(heightOfBT(root->left), heightOfBT(root->right));
}

int diameterOfBT(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }

    int o1 = heightOfBT(root->left) + heightOfBT(root->right);
    int o2 = diameterOfBT(root->left);
    int o3 = diameterOfBT(root->right);

    return max(o1, max(o2, o3));
}

int main() { return 0; }