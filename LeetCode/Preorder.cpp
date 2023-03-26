#include <iostream>
#include <vector>

#include "TreeNode.h"
using namespace std;

/**
 * * Binary Tree Preorder Traversal
 * * Optimized solution
 * * Runtime 0ms(beats 100%)
 * * Memory 8.2mb(beats 99.71%)
 *
 */

void preorder(TreeNode<int>* root, vector<int>& ans) {
    if (root == nullptr) {
        return;
    }
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

vector<int> preorderTraversal(TreeNode<int>* root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

int main() { return 0; }