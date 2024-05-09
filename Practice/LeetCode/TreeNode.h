#include <iostream>
using namespace std;
#include <queue>
class TreeNode {
   public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        this->val = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

TreeNode *createTree() {
    int data;
    cout << "Enter root data: ";
    cin >> data;
    if (data == -1) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(data);
    queue<TreeNode *> pn;
    pn.emplace(root);
    while (!pn.empty()) {
        TreeNode *fn = pn.front();
        pn.pop();
        cout << "Enter left child of " << fn->val << " ";
        cin >> data;
        if (data != -1) {
            TreeNode *nn = new TreeNode(data);
            fn->left = nn;
            pn.emplace(nn);
        }

        cout << "Enter right child of " << fn->val << " ";
        cin >> data;
        if (data != -1) {
            TreeNode *nn = new TreeNode(data);
            fn->right = nn;
            pn.emplace(nn);
        }
    }
    return root;
}

void printTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode *> pn;
    pn.emplace(root);
    while (!pn.empty()) {
        TreeNode *fn = pn.front();
        pn.pop();
        cout << fn->val << ": ";
        if (fn->left) {
            cout << fn->left->val << ", ";
            pn.emplace(fn->left);
        }
        if (fn->right) {
            cout << fn->right->val << ", ";
            pn.emplace(fn->right);
        }

        cout << endl;
    }
    cout << endl;
}
