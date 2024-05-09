#include <iostream>
#include <queue>
#include <vector>

#include "TreeNode.h"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
        return {};
    }

    queue<TreeNode*> pn;
    vector<vector<int>> output;

    pn.push(root);

    while (!pn.empty()) {
        vector<int> smallAns;
        int size = pn.size();
        while (size--) {
            TreeNode* fn = pn.front();
            pn.pop();

            smallAns.push_back(fn->val);
            if (fn->left) {
                pn.push(fn->left);
            }
            if (fn->right) {
                pn.push(fn->right);
            }
        }
        output.push_back(smallAns);
    }
    return output;
}

int main() { return 0; }