#include <iostream>
#include <queue>
using namespace std;
class BTNode {
   public:
    int val;
    BTNode* left;
    BTNode* right;

    BTNode() {
        this->val = -1;
        this->left = nullptr;
        this->right = nullptr;
    }

    BTNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~BTNode() {
        this->left = nullptr;
        this->right = nullptr;
    }
};

BTNode* createTree() {
    int data;
    cout << "enter root data:\n";
    cin >> data;
    BTNode* root = new BTNode(data);
    queue<BTNode*> pn;
    pn.push(root);

    while (!pn.empty()) {
        BTNode* fn = pn.front();
        pn.pop();

        printf("Enter the left child of %d: ", fn->val);
        cin >> data;
        if (data != -1) {
            BTNode* nn = new BTNode(data);
            pn.push(nn);
            fn->left = nn;
        }

        printf("Enter the right child of %d: ", fn->val);
        cin >> data;
        if (data != -1) {
            BTNode* nn = new BTNode(data);
            pn.push(nn);
            fn->right = nn;
        }
    }

    return root;
}

void printTree(BTNode* root) {
    queue<BTNode*> pn;
    pn.push(root);
    while (!pn.empty()) {
        BTNode* fn = pn.front();
        pn.pop();

        if (fn == NULL) {
            printf("\n");
            if (!pn.empty()) {
                pn.push(NULL);
            }
        }
        printf("%d: ", fn->val);
        if (fn->left) {
            pn.push(fn);
            printf("%d, ", fn->left->val);
        }
        if (fn->right) {
            pn.push(fn->right);
            printf("%d, ", fn->right->val);
        }
    }
}