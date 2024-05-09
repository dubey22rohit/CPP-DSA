#include <iostream>
#include <stack>

#include "TreeNode.h"
using namespace std;

vector<int> ans;

void inorder(TreeNode* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
}

int KthSmallestValue(TreeNode* root, int k) {
    inorder(root);
    return ans[k - 1];
}

int main() {
    TreeNode* root = createTree();
    int k;
    cout << "Enter K: ";
    cin >> k;
    int ans = KthSmallestValue(root, k);
    cout << ans;

    return 0;
}