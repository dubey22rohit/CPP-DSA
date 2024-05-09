#include <iostream>

#include "CommonFunctions.h"
using namespace std;

TreeNode<int> *nodeWithMaxChildSum(TreeNode<int> *root) {
    queue<TreeNode<int> *> pn;
    TreeNode<int> *gn;
    pn.emplace(root);
    int currSum = 0;
    int gs = INT32_MIN;
    while (!pn.empty()) {
        currSum = 0;
        TreeNode<int> *curr = pn.front();
        pn.pop();
        currSum += curr->data;
        for (int i = 0; i < curr->children.size(); i++) {
            currSum += curr->children[i]->data;
            pn.emplace(curr->children[i]);
        }
        if (currSum > gs) {
            gs = currSum;
            gn = curr;
        }
    }
    return gn;
}

int main() {
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    cout << endl;
    cout << "Node with max data: " << nodeWithMaxChildSum(root)->data;
    return 0;
}