#include<iostream>
using namespace std;
#include "CommonFunctions.cpp" 

int height(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

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
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout << endl;
    pair<int, int> ans = heightDiameter(root);
    cout << "Height : " << ans.first;
    cout << "Diameter : " << ans.second;
}