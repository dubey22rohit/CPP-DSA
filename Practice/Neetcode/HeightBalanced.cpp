#include <iostream>

#include "TreeNode.h"
using namespace std;

pair<int, bool> heightBalanced(TreeNode* root) {
    if (!root) {
        return {true, 0};
    }

    pair<int, bool> smallAnsL = heightBalanced(root->left);
    pair<int, bool> smallAnsR = heightBalanced(root->right);

    int heightL = smallAnsL.first;
    bool isBalancedL = smallAnsL.second;

    int heightR = smallAnsR.first;
    bool isBalancedR = smallAnsR.second;

    bool ansBalanced =
        abs(heightL - heightR) <= 1 && isBalancedL && isBalancedR;

    int height = max(heightL, heightR) + 1;
    return {height, ansBalanced};
}

bool isBalanced(TreeNode* root) { return heightBalanced(root).first; }

int main() {
    TreeNode* root = createTree();
    printTree(root);

    bool treeBalanced = isBalanced(root);
    cout << "is balanced: " << treeBalanced << endl;

    return 0;
}