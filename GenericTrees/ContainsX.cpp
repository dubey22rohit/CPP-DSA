#include <iostream>

#include "CommonFunctions.h"
using namespace std;

bool containsX(TreeNode<int>* root, int x) {
    if (root->data == x) {
        return true;
    }
    for (int i = 0; i < root->children.size(); i++) {
        bool smallAns = containsX(root->children[i], x);
        if (smallAns) {
            return true;
        }
    }
    return false;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout << endl;
    cout << "Enter element to search: ";
    int x;
    cin >> x;
    printf("\nElement %d present in tree?: %d", x, containsX(root, x));

    return 0;
}