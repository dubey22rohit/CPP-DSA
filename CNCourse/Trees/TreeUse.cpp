#include <iostream>
using namespace std;
#include <queue>

#include "TreeNode.h"

TreeNode<int>* takenInput() {
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter the number of children of , " << rootData << " ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        TreeNode<int>* childNode = takenInput();
        root->children.push_back(childNode);
    }
    return root;
}

TreeNode<int>* takeInputLevelWise() {
    int rd;
    cout << "Enter root data ";
    cin >> rd;
    TreeNode<int>* root = new TreeNode<int>(rd);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        TreeNode<int>* frontNode = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << frontNode->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cout << "Enter " << i << "th child of" << frontNode->data << endl;
            cin >> childData;
            TreeNode<int>* newNode = new TreeNode<int>(childData);
            frontNode->children.push_back(newNode);
            pendingNodes.push(newNode);
        }
    }
    return root;
}

void printTreeLevelWise(TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    cout << root->data << endl;
    while (!q.empty()) {
        TreeNode<int>* currNode = q.front();
        q.pop();
        for (int i = 0; i < currNode->children.size(); i++) {
            cout << currNode->children[i]->data << " ";
            q.push(currNode->children[i]);
        }
        cout << endl;
    }
}

void printTree(TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++) {
        cout << root->children[i]->data << " ,";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++) {
        printTree(root->children[i]);
    }
}

int main() {
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // TreeNode<int>* root = takeInput();
    TreeNode<int>* root = takeInputLevelWise();
    // printTree(root);
    printTreeLevelWise(root);
    delete root;
}