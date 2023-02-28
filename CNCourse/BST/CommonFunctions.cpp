#include <iostream>
using namespace std;
#include <queue>

#include "BTreeNode.h"

BTreeNode<int>* takeInput() {
    int rd;
    cout << "Enter root data " << endl;
    cin >> rd;
    if (rd == -1) {
        return NULL;
    }
    queue<BTreeNode<int>*> pn;
    BTreeNode<int>* root = new BTreeNode<int>(rd);
    pn.push(root);
    while (!pn.empty()) {
        BTreeNode<int>* f = pn.front();
        pn.pop();
        cout << "Enter data for left node of " << f->data;
        int lcd;
        cin >> lcd;
        if (lcd != -1) {
            BTreeNode<int>* lc = new BTreeNode<int>(lcd);
            pn.push(lc);
            f->left = lc;
        }
        cout << "Enter data for right child of " << f->data;
        int rcd;
        cin >> rcd;
        if (rcd != -1) {
            BTreeNode<int>* rc = new BTreeNode<int>(rcd);
            pn.push(rc);
            f->right = rc;
        }
    }
    return root;
}

void printTree(BTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    queue<BTreeNode<int>*> pn;
    pn.push(root);
    while (!pn.empty()) {
        BTreeNode<int>* f = pn.front();
        pn.pop();
        if (f == NULL) {
            cout << endl;
            if (!pn.empty()) {
                pn.push(NULL);
            }
        } else {
            cout << f->data << ":";
            if (f->left) {
                pn.push(f->left);
                cout << f->left->data << ",";
            } else {
                cout << "-1,";
            }
            if (f->right) {
                pn.push(f->right);
                cout << f->right->data;
            } else {
                cout << "-1" << endl;
            }
        }
    }
}