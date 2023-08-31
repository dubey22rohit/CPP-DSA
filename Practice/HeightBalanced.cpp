#include <iostream>

#include "TreeNode.h"
using namespace std;

// int height(TreeNode* root) {
//     if (!root) {
//         return 0;
//     }

//     return 1 + max(height(root->left), height(root->right));
// }

// bool isBalanced(TreeNode* root) {
//     if (!root) {
//         return true;
//     }

//     if (abs(height(root->left) - height(root->right)) <= 1 &&
//         isBalanced(root->left) && isBalanced(root->right)) {
//         return true;
//     }
//     return false;
// }

pair<bool, int> isBalancedHeight(TreeNode* root) {
    if (!root) {
        return {true, 0};
    }

    pair<bool, int> smallAnsL = isBalancedHeight(root->left);
    pair<bool, int> smallAnsR = isBalancedHeight(root->right);

    bool isBalancedL = smallAnsL.first;
    int heightL = smallAnsL.second;

    bool isBalancedR = smallAnsR.first;
    int heightR = smallAnsR.second;

    bool ansBalanced =
        abs(heightL - heightR) <= 1 && isBalancedL && isBalancedR;

    int height = max(heightL, heightR) + 1;
    return {ansBalanced, height};
}

int main() {
    TreeNode* root = createTree();
    printTree(root);

    pair<bool, int> treeBalanced = isBalancedHeight(root);
    cout << "is balanced: " << treeBalanced.first << endl;
    cout << "height: " << treeBalanced.second << endl;

    return 0;
}