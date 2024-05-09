#include <iostream>
#include <vector>

#include "TreeNode.h"
using namespace std;

void rightSideViewHelper(TreeNode* root, int level, vector<int>& ans) {
    if (!root) {
        return;
    }

    if (ans.size() == level) {
        ans.push_back(root->val);
    }
    rightSideViewHelper(root->right, level + 1, ans);
    rightSideViewHelper(root->left, level + 1, ans);
}

vector<int> rightSideView(TreeNode* root) {
    if (!root) {
        return {};
    }
    vector<int> ans;
    rightSideViewHelper(root, 0, ans);
    return ans;
}

int main() {
    TreeNode* root = createTree();
    vector<int> ans = rightSideView(root);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}