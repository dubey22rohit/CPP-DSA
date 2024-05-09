#include <iostream>
#include <stack>

#include "CommonFunctions.h"
using namespace std;

bool hasPathSum(TreeNode<int>* root, int targetSum) {
    if (root == nullptr) {
        return false;
    }
    stack<TreeNode<int>*> pn;
    stack<int> ps;
    pn.push(root);
    ps.push(targetSum - root->val);
    while (!pn.empty()) {
        TreeNode<int>* cn = pn.top();
        int cs = ps.top();
        pn.pop();
        ps.pop();

        if (cn->left == nullptr && cn->right == nullptr && cs == 0) {
            return true;
        }

        if (cn->left != nullptr) {
            pn.push(cn->left);
            ps.push(cs - cn->left->val);
        }

        if (cn->right != nullptr) {
            pn.push(cn->right);
            ps.push(cs - cn->right->val);
        }
    }
    return false;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout << "Path sum? :" << hasPathSum(root, 22);
    return 0;
}
