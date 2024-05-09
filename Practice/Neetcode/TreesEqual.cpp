#include <iostream>

#include "TreeNode.h"
using namespace std;

bool isEqual(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) {
        return true;
    }
    if (!root1 && root2) {
        return false;
    }
    if (root1 && !root2) {
        return false;
    }
    if (root1->val == root2->val && isEqual(root1->left, root2->left) &&
        isEqual(root1->right, root2->right)) {
        return true;
    }
    return false;
}

int main() {
    TreeNode* root1 = createTree();
    printTree(root1);

    TreeNode* root2 = createTree();
    printTree(root2);

    cout << isEqual(root1, root2) << endl;
    return 0;
}