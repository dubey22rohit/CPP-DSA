#include <iostream>

#include "CommonFunctions.h"
using namespace std;

int treeHeight(BTNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    int lh = treeHeight(root->lchild);
    int rh = treeHeight(root->rchild);

    return lh > rh ? lh + 1 : rh + 1;
}

int main() {
    BTNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout << "Tree Height: " << treeHeight(root);
    return 0;
}