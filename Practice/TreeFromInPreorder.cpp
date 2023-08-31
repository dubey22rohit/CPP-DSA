#include <iostream>
#include <vector>

#include "TreeNode.h"
using namespace std;

TreeNode* treeFromInPreorder(vector<int>& pre, vector<int>& in) {
    if (pre.size() == 0 && in.size() == 0) {
        return nullptr;
    }
    if (pre.size() == 0) {
        return nullptr;
    }

    int root = pre[0];
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> pre(m);
    vector<int> in(n);

    int a = -1;
    for (int i = 0; i < m; i++) {
        cin >> a;
        pre.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        cin >> a;
        in.push_back(a);
    }

    TreeNode* root = treeFromInPreorder(pre, in);
    printTree(root);
    return 0;
}