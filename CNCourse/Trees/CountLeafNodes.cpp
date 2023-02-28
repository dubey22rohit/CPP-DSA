#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

int countLeafNodes(TreeNode<int>* root) {
    int ans = 0;
    if (root->children.size() == 0) {
        ans = 1;
    }
    for (int i = 0; i < root->children.size(); i++) {
        ans += countLeafNodes(root->children[i]);
    }
    return ans;
}
int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << countLeafNodes(root);
}