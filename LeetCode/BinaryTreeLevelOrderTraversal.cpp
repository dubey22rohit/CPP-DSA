#include <iostream>
#include <queue>
#include <vector>

#include "TreeNode.h"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
        return {};
    }

    vector<vector<int>> output;
    queue<TreeNode*> pn;

    pn.emplace(root);

    while (!pn.empty()) {
        vector<int> smallAns;
        int size = pn.size();

        while (size--) {
            TreeNode* fn = pn.front();
            pn.pop();

            smallAns.push_back(fn->val);

            if (fn->left) {
                pn.emplace(fn->left);
            }

            if (fn->right) {
                pn.emplace(fn->right);
            }
        }
        output.push_back(smallAns);
    }

    return output;
}

int main() {
    TreeNode* root = createTree();

    vector<vector<int>> ans = levelOrder(root);

    for (int i = 0; i < ans.size(); i++) {
        vector<int> smallAns = ans[i];
        cout << "[ ";
        for (int j = 0; j < smallAns.size(); j++) {
            cout << smallAns[j] << ",";
        }
        cout << " ]";
    }

    return 0;
}