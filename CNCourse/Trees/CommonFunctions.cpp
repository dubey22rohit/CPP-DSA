#include <queue>

#include "TreeNode.h"
TreeNode<int>* takeInputLevelWise() {
    int rd;
    cout << "Enter root data";
    cin >> rd;
    TreeNode<int>* root = new TreeNode<int>(rd);
    queue<TreeNode<int>*> pn;
    pn.push(root);
    while (!pn.empty()) {
        TreeNode<int>* fn = pn.front();
        pn.pop();
        cout << "Enter the number of children for " << fn->data;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++) {
            cout << "Enter " << i << "th child of " << fn->data;
            int childData;
            cin >> childData;
            TreeNode<int>* nn = new TreeNode<int>(childData);
            fn->children.push_back(nn);
            pn.push(nn);
        }
    }
    return root;
}

void printTree(TreeNode<int>* root) {
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++) {
        cout << root->children[i]->data;
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++) {
        printTree(root->children[i]);
    }
}

void printTreeLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pn;
    cout << root->data << endl;
    pn.push(root);
    while (!pn.empty()) {
        TreeNode<int>* front = pn.front();
        pn.pop();
        for (int i = 0; i < front->children.size(); i++) {
            cout << front->children[i]->data << " ";
            pn.push(front->children[i]);
        }
        cout << endl;
    }
}