#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

bool searchInBST(BTreeNode<int>* root, int k) {
    if (root == NULL) {
        return false;
    }
    bool ans;
    if (root->data == k) {
        return true;
    } else if (root->data < k) {
        ans = searchInBST(root->right, k);
    } else {
        ans = searchInBST(root->left, k);
    }
    return ans;
}

int main() {
    BTreeNode<int>* root = takeInput();
    printTree(root);
    cout << endl;
    cout << searchInBST(root, 12);
}