#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

int height(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    int ans = 1;
    int lh = height(root->left);
    int rh = height(root->right);
    return lh > rh ? ans + lh : ans + rh; 
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << height(root);
}