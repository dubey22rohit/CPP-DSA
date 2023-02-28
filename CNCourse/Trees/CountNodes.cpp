#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

int numNodes(TreeNode<int>* root) {
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++) {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << numNodes(root);
}