#include <queue>

#include "TreeNode.h"

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter root data";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pn;
    pn.emplace(root);
    while (!pn.empty()) {
        TreeNode<int>* currNode = pn.front();
        pn.pop();
        printf("Enter the number of children of %d\n", currNode->data);
        int numChild;
        cin >> numChild;
        printf("Enter %d children of %d: \n", numChild, currNode->data);
        for (int i = 0; i < numChild; i++) {
            int childData;
            printf("Enter %d st/rd child of %d: ", i, currNode->data);
            cin >> childData;
            TreeNode<int>* nn = new TreeNode<int>(childData);
            currNode->children.push_back(nn);
            pn.emplace(nn);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pn;
    pn.emplace(root);
    while (!pn.empty()) {
        TreeNode<int>* curr = pn.front();
        pn.pop();
        printf("%d: ", curr->data);
        for (int i = 0; i < curr->children.size(); i++) {
            printf("%d ", curr->children[i]->data);
            pn.emplace(curr->children[i]);
        }
        cout << endl;
    }
    return;
}