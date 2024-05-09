#include <iostream>

#include "TreeNode.h"
using namespace std;

// Diameter: Length of the longest path, through the root
// DFS: TC: O(N), SC: O(N)
pair<int, int> heightDiameter(TreeNode* root) {
    if (root == nullptr) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->lchild);
    pair<int, int> rightAns = heightDiameter(root->rchild);

    int lh = leftAns.first;
    int ld = leftAns.second;

    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;

    return p;
}

int main() {
    TreeNode* root = createTree();
    printTree(root);
    pair<int, int> p = heightDiameter(root);
    cout << "height: " << p.first << ", diameter: " << p.second;
    return 0;
}