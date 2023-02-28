#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"
bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    if (root == NULL) {
        return false;
    } else if (root->data == x) {
        return true;
    }
    bool leftAns = isNodePresent(root->left, x);
    bool rightAns = isNodePresent(root->right, x);
    return leftAns || rightAns;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << endl;
    cout << isNodePresent(root, 2);
}