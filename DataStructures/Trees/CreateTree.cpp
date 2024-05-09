#include <iostream>
#include <queue>

#include "Queue.h"
using namespace std;

struct BTreeNode *root = NULL;

void CreateTree() {
    struct BTreeNode *p, *t;

    int x;

    struct Queue q;
    Create(&q, 100);

    printf("Enter root data");
    scanf("%d", &x);
    root = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    root->data = x;
    root->lchild = root->rchild = NULL;
    Enqueue(&q, root);
    while (!isEmpty(&q)) {
        p = Dequeue(&q);

        printf("Enter left child of %d", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Enqueue(&q, t);
        }
        printf("Enter right child of %d", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Enqueue(&q, t);
        }
    }
}

void Preorder(struct BTreeNode *p) {
    if (p) {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct BTreeNode *p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct BTreeNode *p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main() {
    CreateTree();
    cout << "\nPreorder : ";
    Preorder(root);
    cout << "\nInorder : ";
    Inorder(root);
    cout << "\nPostorder : ";
    Postorder(root);
    return 0;
}