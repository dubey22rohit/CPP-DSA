#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

int NodesSum(TreeNode<int>* root) {
    int ans = 0;
    ans = root->data;
    for (int i = 0; i < root->children.size(); i++) {
        ans += NodesSum(root->children[i]);
    }
    return ans;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int sum = NodesSum(root);
    cout << sum;
}