#include <queue>

#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise() {
    cout << "Enter root data: ";
    int rd, x;
    cin >> rd;
    TreeNode<int>* root = new TreeNode<int>(rd);
    queue<TreeNode<int>*> pn;
    pn.push(root);
    while (!pn.empty()) {
        TreeNode<int>* cn = pn.front();
        pn.pop();

        printf("Enter the left child of %d: ", cn->val);
        cin >> x;
        if (x != -1) {
            TreeNode<int>* lchild = new TreeNode<int>(x);
            cn->left = lchild;
            pn.push(lchild);
        }

        printf("Enter the right child of %d: ", cn->val);
        cin >> x;
        if (x != -1) {
            TreeNode<int>* rchild = new TreeNode<int>(x);
            cn->right = rchild;
            pn.push(rchild);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int>* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode<int>*> pn;
    pn.push(root);
    while (!pn.empty()) {
        TreeNode<int>* cn = pn.front();
        pn.pop();
        cout << cn->val << ": ";
        if (cn->left) {
            cout << "L:" << cn->left->val << ", ";
            pn.push(cn->left);
        } else {
            cout << "-1"
                 << ", ";
        }
        if (cn->right) {
            cout << "R:" << cn->right->val << ", ";
            pn.push(cn->right);
        } else {
            cout << "-1"
                 << ", ";
        }
        cout << endl;
    }
}