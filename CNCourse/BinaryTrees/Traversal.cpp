#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

void inorder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << endl;
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    cout << "Preorder : ";
    preorder(root);
    cout << endl;

    cout << "Inorder : ";
    inorder(root);
    cout << endl;

    cout << "Postorder : ";
    postorder(root);
    cout << endl;
}