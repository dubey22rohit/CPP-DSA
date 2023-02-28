#include <iostream>
using namespace std;
#include <climits>

#include "CommonFunctions.cpp"

int minimum(BTreeNode<int>* root) {
    if (root == NULL) {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BTreeNode<int>* root) {
    if (root == NULL) {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(BTreeNode<int>* root) {
    if (root == NULL) {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool ans = (root->data > leftMax) && (root->data <= rightMin) &&
               isBST(root->left) && isBST(root->right);
    return ans;
}

int main() {
    BTreeNode<int>* root = takeInput();
    printTree(root);
    cout << endl;
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    isBST(root) ? cout << "True" : cout << "False";
}