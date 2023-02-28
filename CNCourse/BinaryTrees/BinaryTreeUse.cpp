#include <iostream>
using namespace std;
#include <queue>

#include "BinaryTreeNode.h"

void printRecursive(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " : ";
    if (root->left != NULL) {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL) {
        cout << "R" << root->right->data << " ";
    }
    cout << endl;
    printRecursive(root->left);
    printRecursive(root->right);
}

void printLevelWise(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if (front == NULL) {
            cout << endl;
            if (!pendingNodes.empty()) {
                pendingNodes.push(NULL);
            }
        } else {
            cout << front->data << ":";
            cout << "L:";
            if (front->left) {
                pendingNodes.push(front->left);
                cout << front->left->data << ",";
            } else {
                cout << "-1"
                     << ",";
            }
            cout << "R : ";
            if (front->right) {
                pendingNodes.push(front->right);
                cout << front->right->data << endl;
            } else {
                cout << "-1" << endl;
            }
        }
    }
}

BinaryTreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1) {
            BinaryTreeNode<int>* leftChild =
                new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout << "Enter right child of " << front->data;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1) {
            BinaryTreeNode<int>* rightChild =
                new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

BinaryTreeNode<int>* takeInputRecursive() {
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInputRecursive();
    BinaryTreeNode<int>* rightChild = takeInputRecursive();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

void levelOrderTraversal(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);
    pn.push(NULL);
    while (!pn.empty()) {
        BinaryTreeNode<int>* front = pn.front();
        pn.pop();
        if (front == NULL) {
            cout << endl;
            if (!pn.empty()) {
                pn.push(NULL);
            }
        } else {
            cout << front->data << " ";
            if (front->left) {
                pn.push(front->left);
            }
            if (front->right) {
                pn.push(front->right);
            }
        }
    }
}
int main() {
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;
    // BinaryTreeNode<int>* root = takeInputRecursive();
    BinaryTreeNode<int>* root = takeInputLevelWise();
    // printRecursive(root);
    // printLevelWise(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    cout << "Level Order : " << endl;
    levelOrderTraversal(root);
    delete root;
}