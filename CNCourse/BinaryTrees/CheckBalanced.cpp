#include <iostream>
using namespace std;
#include <cstdlib>

#include "CommonFunctions.cpp"

int height(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return lh > rh ? lh + 1 : rh + 1;
}

bool checkBalanced(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1) {
        return true;
    }
    return false;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << "Is Balanced " << endl;
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    cout << checkBalanced(root);
}