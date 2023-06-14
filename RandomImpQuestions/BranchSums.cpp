#include <iostream>
#include <vector>

#include "TreeNode.h"
using namespace std;

// TC: O(n)
// SC: O(n)
void branchSumsHelper(TreeNode* root, vector<int>& ans, int rs) {
    if (!root->lchild && !root->rchild) {
        ans.push_back(rs + root->data);
        return;
    }
    if (root->lchild) {
        branchSumsHelper(root->lchild, ans, rs + root->data);
    }
    if (root->rchild) {
        branchSumsHelper(root->rchild, ans, rs + root->data);
    }
}

vector<int> branchSums(TreeNode* root) {
    vector<int> ans;
    branchSumsHelper(root, ans, 0);
    return ans;
}

int main() {
    TreeNode* root = createTree();
    printTree(root);
    vector<int> ans = branchSums(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}