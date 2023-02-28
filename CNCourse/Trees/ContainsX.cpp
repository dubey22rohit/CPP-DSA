#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

bool containsX(TreeNode<int>* root, int x) {
    if (root->data == x) {
        return true;
    }
    for (int i = 0; i < root->children.size(); i++) {
        bool ans = containsX(root->children[i], x);
        if(ans == true){
            return true;
        }
    }
    return false;
}

int main() {
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int>* root = takeInputLevelWise();
    cout << endl;
    cout << containsX(root, 9);
}