#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
   public:
    int data;
    TreeNode* lchild;
    TreeNode* rchild;

    TreeNode() {
        this->data = -1;
        this->lchild = nullptr;
        this->rchild = nullptr;
    }

    TreeNode(int data) {
        this->data = data;
        this->lchild = nullptr;
        this->rchild = nullptr;
    }

    ~TreeNode() {
        delete lchild;
        delete rchild;
    }
};

TreeNode* createTree() {
    cout << "Enter root data: ";
    int data;
    cin >> data;
    TreeNode* root = new TreeNode(data);
    queue<TreeNode*> pn;
    pn.push(root);
    while (!pn.empty()) {
        TreeNode* cn = pn.front();
        pn.pop();

        printf("Enter the left child of %d: ", cn->data);
        cin >> data;
        if (data != -1) {
            TreeNode* nn = new TreeNode(data);
            cn->lchild = nn;
            pn.push(nn);
        }

        printf("Enter the right child of %d: ", cn->data);
        cin >> data;
        if (data != -1) {
            TreeNode* nn = new TreeNode(data);
            cn->rchild = nn;
            pn.push(nn);
        }
    }
    return root;
}

void printTree(TreeNode* root) {
    queue<TreeNode*> pn;
    pn.push(root);
    while (!pn.empty()) {
        TreeNode* cn = pn.front();
        pn.pop();

        cout << cn->data << ": ";
        if (cn->lchild) {
            cout << cn->lchild->data << ", ";
            pn.push(cn->lchild);
        }
        if (cn->rchild) {
            cout << cn->rchild->data << ", ";
            pn.push(cn->rchild);
        }
        cout << endl;
    }
    cout << endl;
}
