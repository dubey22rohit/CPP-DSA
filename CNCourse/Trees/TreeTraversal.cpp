#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

void preorder(TreeNode<int>* root) {
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++) {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int>* root) {
    for (int i = 0; i < root->children.size(); i++) {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}

int main() {
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int>* root = takeInputLevelWise();
    string ans = preorderStr(root);
    cout << ans;
    // preorder(root);
}