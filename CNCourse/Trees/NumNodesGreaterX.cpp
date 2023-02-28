#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

int nodesGreaterThanX(TreeNode<int>* root, int x) {
    int ans = 0;
    if (root->data > x) {
        ans = 1;
    }
    for (int i = 0; i < root->children.size(); i++) {
        ans += nodesGreaterThanX(root->children[i], x);
    }
    return ans;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << nodesGreaterThanX(root, 1);
}