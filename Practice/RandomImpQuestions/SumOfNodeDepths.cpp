#include <iostream>

#include "TreeNode.h"
using namespace std;

// static int cs = 0;
int NodeDepths(TreeNode* root) {}

int main() {
    TreeNode* root = createTree();

    int ans = NodeDepths(root);
    cout << ans;
    return 0;
}