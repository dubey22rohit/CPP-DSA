#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
   public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~TreeNode() {
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* createTree() {
    int data;
    cout << "Enter root data: ";
    cin >> data;
    TreeNode* root = new TreeNode(data);
    queue<TreeNode*> pn;
    pn.push(root);
    while (!pn.empty()) {
        TreeNode* fn = pn.front();
        pn.pop();

        printf("enter the left child of %d", fn->data);
        cin >> data;
        if (data != -1) {
            TreeNode* lchild = new TreeNode(data);
            fn->left = lchild;
            pn.push(lchild);
        }

        printf("enter the right child of %d", fn->data);
        cin >> data;
        if (data != -1) {
            TreeNode* rchild = new TreeNode(data);
            fn->right = rchild;
            pn.push(rchild);
        }

        cout << "\n";
    }

    return root;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << "-1";
    }

    queue<TreeNode*> pn;
    pn.push(root);

    while (!pn.empty()) {
        TreeNode* fn = pn.front();
        pn.pop();

        cout << fn->data << ": ";

        if (fn->left) {
            pn.push(fn->left);
            cout << fn->left->data << ", ";
        }

        if (fn->right) {
            pn.push(fn->right);
            cout << fn->right->data;
        }

        cout << "\n";
    }
    cout << "\n";
}