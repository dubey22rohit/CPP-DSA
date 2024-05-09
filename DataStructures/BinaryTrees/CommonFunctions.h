#include <queue>

#include "BTNode.h"
using namespace std;

BTNode<int>* takeInputLevelWise() {
    cout << "Enter root data: " << endl;
    int rd, x;
    cin >> rd;
    BTNode<int>* root = new BTNode<int>(rd);
    queue<BTNode<int>*> pn;
    pn.emplace(root);
    while (!pn.empty()) {
        BTNode<int>* curr = pn.front();
        pn.pop();
        printf("Enter the left child of %d: ", curr->data);
        cin >> x;
        if (x != -1) {
            BTNode<int>* lc = new BTNode<int>(x);
            curr->lchild = lc;
            pn.emplace(lc);
        }

        cout << endl;

        printf("Enter the right child of %d: ", curr->data);
        cin >> x;
        if (x != -1) {
            BTNode<int>* rc = new BTNode<int>(x);
            curr->rchild = rc;
            pn.emplace(rc);
        }
    }
    return root;
}

void printLevelWise(BTNode<int>* root) {
    if (root == nullptr) {
        return;
    }
    queue<BTNode<int>*> pn;
    pn.emplace(root);
    while (!pn.empty()) {
        BTNode<int>* curr = pn.front();
        pn.pop();
        if (curr == NULL) {
            cout << endl;
            if (!pn.empty()) {
                pn.push(NULL);
            }
        } else {
            cout << curr->data << ": ";
            cout << "L: ";
            if (curr->lchild) {
                pn.emplace(curr->lchild);
                cout << curr->lchild->data << " ";
            } else {
                cout << "-1"
                     << ", ";
            }
            cout << "R: ";
            if (curr->rchild) {
                pn.emplace(curr->rchild);
                cout << curr->rchild->data << " ";
            } else {
                cout << "-1"
                     << ", ";
            }
        }
        cout << endl;
    }
}