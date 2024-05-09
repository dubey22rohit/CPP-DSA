#include <iostream>
#include <vector>

#include "TreeNode.h"
using namespace std;

int dfs(TreeNode* root, vector<int>& res) {
    if (!root) {
        return 0;
    }

    int lm = dfs(root->left, res);
    int rm = dfs(root->right, res);
    lm = max(lm, 0);
    rm = max(rm, 0);

    // compute max path sum with split
    res[0] = max(res[0], root->val + lm + rm);

    // return max path sum without split
    return root->val + max(lm, rm);
}

int maxPathSum(TreeNode* root) {
    vector<int> res{root->val};
    dfs(root, res);
    return res[0];
}

int main() {
    TreeNode* root = createTree();
    printTree(root);
    cout << "\n";
    cout << maxPathSum(root);
    return 0;
}