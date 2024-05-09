#include <iostream>

#include "TreeNode.h"
using namespace std;

int dfs(TreeNode* root, int maxVal) {
    if (!root) {
        return 0;
    }

    int res = 0;
    if (root->val >= maxVal) {
        res = 1;
    }

    maxVal = max(maxVal, root->val);

    res += dfs(root->left, maxVal);
    res += dfs(root->right, maxVal);

    return res;
}
int goodNodes(TreeNode* root) { return dfs(root, root->val); }

int main() {
    TreeNode* root = createTree();
    printTree(root);

    cout << goodNodes(root);
    return 0;
}