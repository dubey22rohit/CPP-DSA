#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

int countNodes(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    int num = 1;
    int c1 = countNodes(root->left);
    int c2 = countNodes(root->right);
    return num + c1 + c2;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << countNodes(root);
}