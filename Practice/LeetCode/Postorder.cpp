#include <iostream>
#include <vector>

#include "TreeNode.h"
using namespace std;

/*
!Can be more optimized
*Runtime 3ms (beats 51.7%)
* Memory 8.6mb (beats 20%)
*/

void postorder(TreeNode<int>* root, vector<int>& ans) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode<int>* root) {
    vector<int> ans;
    postorder(root, ans);
    return ans;
}

int main() { return 0; }