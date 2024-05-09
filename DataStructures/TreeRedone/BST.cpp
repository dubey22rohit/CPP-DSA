#include <iostream>
#include <queue>

#include "TreeClass.h"
using namespace std;

BTNode *FindElement(BTNode *p, int x) {
    // Takes O(logn) time, logn is the height of the tree
    if (p == NULL) {
        return NULL;
    }
    if (p->data == x) {
        return p;
    } else if (p->data > x) {
        return FindElement(p->lchild, x);
    } else {
        return FindElement(p->rchild, x);
    }
    return NULL;
}

void InsertElement(BTNode *p, int x) {
    BTNode *t = NULL;
    BTNode *nn;

    while (p != NULL) {
        t = p;
        if (p->data == x) {
            cout << "Element already present in BST";
            return;
        } else if (p->data < x) {
            p = p->rchild;
        } else {
            p = p->lchild;
        }
    }
    nn = new BTNode;
    nn->data = x;
    nn->lchild = nullptr;
    nn->rchild = nullptr;
    if (t->data < x) {
        t->rchild = nn;
    } else {
        t->lchild = nn;
    }
}

BTNode *Insertr(BTNode *p, int key) {
    BTNode *t;
    if (p == NULL) {
        t = new BTNode;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }

    if (key < p->data) {
        p->lchild = Insertr(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = Insertr(p->rchild, key);
    } else {
        cout << "Key already exists";
        return NULL;
    }
    return p;
}

BTNode *DeleteNode(BTNode *p, int x) {
    if (x < p->data) {
    }
}

int main() {
    Tree root;

    BTNode *bt = root.CreateTree();

    printf("\nInitial Preorder of BST:\n");
    root.Preorder(bt);

    int x;
    cout << "\nEnter element to find : ";
    cin >> x;

    BTNode *ans = FindElement(bt, x);
    printf("Element %d found in tree ? Data : %d\n", x, ans->data);

    cout << "Enter data to insert in BST(Iterative) ";
    cin >> x;
    InsertElement(bt, x);

    cout << "Enter data iteratively to insert in BST(Recursive) ";
    cin >> x;
    BTNode *newTree = Insertr(bt, x);

    printf("\nPreorder of BST after inserting %d\n", x);
    root.Preorder(newTree);

    return 0;
}