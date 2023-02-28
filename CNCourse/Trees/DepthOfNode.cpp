#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"
void printAtLevelK(TreeNode<int>* root, int k) {
    if (root == NULL) {
        return;
    }
    if (k == 0) {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++) {
        printAtLevelK(root->children[i], k - 1);
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printAtLevelK(root, 1);
}