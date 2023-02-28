#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

bool isIdentical(TreeNode<int>* root1, TreeNode<int>* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) {
        return false;
    }
    if ((root1->data != root2->data) ||
        (root1->children.size() != root2->children.size())) {
        return false;
    }
    int i = 0;
    while (i < root1->children.size()) {
        TreeNode<int>* c1 = root1->children[i];
        TreeNode<int>* c2 = root2->children[i];
        if (isIdentical(c1, c2)) {
            i++;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    cout << endl;
    cout << isIdentical(root1, root2);
}