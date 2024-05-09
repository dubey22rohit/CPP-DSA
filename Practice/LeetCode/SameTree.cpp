#include <iostream>

#include "TreeNode.h"
using namespace std;

bool sameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr || q == nullptr) {
        return p == q;
    }
    if (p->val != q->val) {
        return false;
    }

    return sameTree(p->left, q->left) && sameTree(p->right, q->right);
}

int main() {
    TreeNode* p = createTree();
    printTree(p);
    TreeNode* q = createTree();
    printTree(q);

    cout << (sameTree(p, q) ? "same" : "different");
    return 0;
}