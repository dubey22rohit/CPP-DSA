#include <iostream>
#include <vector>

#include "TreeNode.h"
using namespace std;

void branchSumsHelper(TreeNode *root, vector<int> &nums) {
    if (root == nullptr) {
        return;
    }
    int lsum = branchSumsHelper(root->lchild, nums);
    int rsum = branchSumsHelper(root->rchild, nums);
}

vector<int> branchSums(TreeNode *root) {
    vector<int> nums;
    branchSumsHelper(root, nums);
    return nums;
}

int main() {
    TreeNode *root = createTree();
    printTree(root);
    vector<int> ans = branchSums(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}