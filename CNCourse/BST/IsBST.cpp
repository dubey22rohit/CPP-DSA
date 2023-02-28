#include <iostream>
using namespace std;
#include <climits>

#include "CommonFunctions.cpp"

bool isBSTHelper(BTreeNode<int>* root, int min, int max) {
    if (root == NULL) {
        return true;
    }
    if ((root->data < min) || (root->data > max)) {
        return false;
    }
    bool la = isBSTHelper(root->left, min, root->data);
    bool ra = isBSTHelper(root->right, root->data, max);
    return la && ra;
}

bool isBST(BTreeNode<int>* root) { return isBSTHelper(root, INT_MIN, INT_MAX); }

int main() {
    BTreeNode<int>* root = takeInput();
    printTree(root);
    cout << endl;
    cout << isBST(root);
}