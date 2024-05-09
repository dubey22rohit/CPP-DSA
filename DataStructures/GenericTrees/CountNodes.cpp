#include <iostream>

#include "CommonFunctions.h"
using namespace std;

int nodesCount(TreeNode<int>* root) {
    if (root == NULL) {
        return 1;
    }
    int smallAns;
    for (int i = 0; i < root->children.size(); i++) {
        smallAns += nodesCount(root->children[i]);
    }
    return 1 + smallAns;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout << endl;
    cout << "Number of nodes: " << nodesCount(root);
    cout << endl;
    return 0;
}