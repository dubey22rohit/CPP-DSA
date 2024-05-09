#include <iostream>
#include <queue>

#include "BTNode.cpp"
using namespace std;

BTNode<int>* takeInputLevelWise() {
    int val;
    cout << "Enter root data: ";
    cin >> val;
    BTNode<int>* root = new BTNode<int>(val);
    BTNode<int>*cn, *nn;
    queue<BTNode<int>*> pn;
    pn.emplace(root);
    while (!pn.empty()) {
        cn = pn.front();
        pn.pop();
        printf("Enter the left child of %d: ", cn->data);
        cin >> val;
        if (val != -1) {
            nn = new BTNode<int>(val);
            cn->lchild = nn;
            pn.emplace(nn);
        }

        printf("Enter the right child of %d: ", cn->data);
        cin >> val;
        if (val != -1) {
            nn = new BTNode<int>(val);
            cn->rchild = nn;
            pn.emplace(nn);
        }
    }
    return root;
}

void printTreeLevelWise(BTNode<int>* root) {
    BTNode<int>* cn;
    queue<BTNode<int>*> pn;
    pn.emplace(root);
    while (!pn.empty()) {
        cn = pn.front();
        pn.pop();
        printf("Parent: %d ", cn->data);
        if (cn->lchild) {
            printf("L: %d, ", cn->lchild->data);
            pn.emplace(cn->lchild);
        }
        if (cn->rchild) {
            printf("R: %d", cn->rchild->data);
            pn.emplace(cn->rchild);
        }
        cout << endl;
    }
}

bool searchTree(BTNode<int>* root, int val) {
    BTNode<int>* rp = root;
    while (rp != nullptr) {
        if (val < rp->data) {
            rp = rp->lchild;
        } else if (val > rp->data) {
            rp = rp->rchild;
        } else {
            return true;
        }
    }
    return false;
}

void insert(BTNode<int>* root, int val) {
    BTNode<int>* rp = root;

    while (rp->lchild != nullptr || rp->rchild != nullptr) {
        if (val < rp->data) {
            rp = rp->lchild;
        } else if (val > rp->data) {
            rp = rp->rchild;
        } else {
            cout << "Value already exists";
            return;
        }
    }

    BTNode<int>* nn = new BTNode<int>(val);
    if (val < rp->data) {
        rp->lchild = nn;
    } else {
        rp->rchild = nn;
    }
}

BTNode<int>* deleteNode(BTNode<int>* root, int val) {
    BTNode<int>*rp = root, *tail = root, *rm = nullptr;
    while (rp->data != val) {
        if (val < rp->data) {
            tail = rp;
            rp = rp->lchild;
        } else if (val > rp->data) {
            tail = rp;
            rp = rp->rchild;
        }
    }
    if (tail->data > rp->data) {
        rm = tail->lchild;
        tail->lchild = nullptr;
    } else {
        rm = tail->rchild;
        tail->rchild = nullptr;
    }
    return rm;
}

int main() {
    // 20 10 30 5 15 25 35 -1 -1 -1 -1 -1 -1 -1 -1
    BTNode<int>* root = takeInputLevelWise();
    cout << "\n";
    printTreeLevelWise(root);
    cout << "\n";
    insert(root, 125);
    cout << "\n Tree after inserting:\n";
    printTreeLevelWise(root);
    cout << "\n";
    cout << "\n Searching for 125, present?: " << searchTree(root, 125);
    cout << "\n";
    BTNode<int>* deletedNode = deleteNode(root, 125);
    cout << "Deleted Node: " << deletedNode->data << endl;
    cout << "Tree after deleting:\n";
    printTreeLevelWise(root);
    return 0;
}