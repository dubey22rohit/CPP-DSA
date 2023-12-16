#include <iostream>

#include "TreeNode.h"
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q) {
        return false;
    }

    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main() { return 0; }