#include <iostream>

#include "TreeNode.h"
using namespace std;

void tree2str(TreeNode* root, string& ans) {
    if (root == NULL) {
        return;
    }

    ans += to_string(root->val);

    if (!root->left && !root->right) {
        return;
    }

    if (root->left) {
        ans += '(';
        tree2str(root->left, ans);
        ans += ')';
    }

    if (root->right) {
        ans += '(';
        tree2str(root->right, ans);
        ans += ')';
    }
}

string tree2str(TreeNode* root) {
    string ans;
    tree2str(root, ans);
    return ans;
}

int main() {
    TreeNode* root = createTree();
    string ans = tree2str(root);
    cout << ans;
    return 0;
}