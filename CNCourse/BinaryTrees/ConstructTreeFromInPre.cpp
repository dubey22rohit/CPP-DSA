#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

// Constructing a binary tree from Inorder and Preorder
// Inorder = left root right
// Preorder = root left right

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
    if (inS > inE) {
        return NULL;
    }
    int rootData = pre[preS];
    int rootIndex = -1;
    // For finding the index of root in inorder
    for (int i = inS; i <= inE; i++) {
        if (in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }
    int lPreS = preS + 1;
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreE = lInE - lInS + lPreS;

    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPreS = lPreE + 1;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreeNode<int>* buildTree(int* in, int* pre, int size) {
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

int main() {
    int in[] = { 4, 2, 5, 1, 8, 6, 9, 3, 7 };
    int pre[] = { 1, 2, 4, 5, 3, 6, 8, 9, 7 };
    BinaryTreeNode<int>* root = buildTree(in, pre, 9);
    printLevelWise(root);
}