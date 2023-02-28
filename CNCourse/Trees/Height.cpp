#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

int height(TreeNode<int>* root) {
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++) {
        int childHeight = height(root->children[i]);
        if (childHeight > ans) {
            ans = childHeight;
        }
    }
    return ans + 1;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << height(root);
}