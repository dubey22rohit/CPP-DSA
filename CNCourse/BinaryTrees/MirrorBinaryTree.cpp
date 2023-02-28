#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    BinaryTreeNode<int>* tl = root->left;
    root->left = root->right;
    root->right = tl;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << endl;
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    mirrorBinaryTree(root);
    printLevelWise(root);

}