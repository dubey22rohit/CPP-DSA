#include <iostream>

#include "TreeNode.h"

using namespace std;

pair<int, int> heightDiameter(TreeNode* root) {
    if (!root) {
        return {0, 0};
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;

    int rh = rightAns.first;
    int rd = rightAns.second;

    int h = 1 + max(lh, rh);
    int d = max(lh + rh, max(ld, rd));

    return {h, d};
}

int diameterOfBinaryTree(TreeNode* root) { return heightDiameter(root).second; }

int main() {
    TreeNode* root = createTree();
    printTree(root);
    return 0;
}