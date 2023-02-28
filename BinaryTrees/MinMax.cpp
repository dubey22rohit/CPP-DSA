#include <iostream>

#include "CommonFunctions.h"
using namespace std;

Pair<int, int> minMaxInBTree(BTNode<int>* root) {
    if (root == NULL) {
        return make_pair(-1, -1);
    }
}

int main() {
    BTNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    return 0;
}