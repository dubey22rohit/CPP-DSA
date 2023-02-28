#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

int sumOfNodes(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    int ans = root->data;
    int sa1 = sumOfNodes(root->left);
    int sa2 = sumOfNodes(root->right);
    return ans + sa1 + sa2;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << sumOfNodes(root);
}