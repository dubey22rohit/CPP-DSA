#include "BinaryTreeNode.h"
using namespace std;
#include <queue>

BinaryTreeNode<int>* takeInputLevelWise() {
    int rd;
    cout << "Enter root data : " << endl;
    cin >> rd;
    if (rd == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rd);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter data for left node of" << front->data;
        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        cout << "Enter data for right node of" << front->data;
        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            BinaryTreeNode<int>* rightChild =
                new BinaryTreeNode<int>(rightData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void printRecursive(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    if (root->left) {
        cout << "L" << root->left->data;
    }
    if (root->right) {
        cout << "R" << root->right->data;
    }
    printRecursive(root->left);
    printRecursive(root->right);
}

void printLevelWise(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);
    while (!pn.empty()) {
        BinaryTreeNode<int>* front = pn.front();
        pn.pop();
        if (front == NULL) {
            cout << endl;
            if (!pn.empty()) {
                pn.push(NULL);
            }
        }
        else {
            cout << front->data << ":";
            cout << "L:";
            if (front->left) {
                pn.push(front->left);
                cout << front->left->data << ",";
            }
            else {
                cout << "-1,";
            }
            cout << "R";
            if (front->right) {
                pn.push(front->right);
                cout << front->right->data << endl;
            }
            else {
                cout << "-1\n";
            }
        }
    }
}

BinaryTreeNode<int>* takeInputLevelWise2() {
    int rd;
    cout << "enter root data" << " ";
    cin >> rd;
    if (rd == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rd);
    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);
    while (!pn.empty()) {
        BinaryTreeNode<int>* f = pn.front();
        pn.pop();

        cout << "Enter data for left child of : " << f->data;
        int ld;
        cin >> ld;
        if (ld != -1) {
            BinaryTreeNode<int>* lc = new BinaryTreeNode<int>(ld);
            pn.push(lc);
            root->left = lc;
        }

        cout << "Enter data for right child of : " << f->data;
        int rd;
        cin >> rd;
        if (rd != -1) {
            BinaryTreeNode<int>* rc = new BinaryTreeNode<int>(rd);
            pn.push(rc);
            root->right = rc;
        }
    }
    return root;
}