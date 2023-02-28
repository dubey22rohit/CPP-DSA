#include <iostream>

#include "CommonFunctions.h"
using namespace std;

bool isNodePresent(BTNode<int>* root, int x) {
    if (root == NULL) {
        return false;
    } else if (root->data == x) {
        return true;
    }

    bool lans = isNodePresent(root->lchild, x);
    bool rans = isNodePresent(root->rchild, x);

    return lans || rans;
}

int main() {
    BTNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    printf("Enter the value to search: ");
    int x;
    cin >> x;
    printf("%d present in Binary Tree?: %d", x, isNodePresent(root, x));
    return 0;
}