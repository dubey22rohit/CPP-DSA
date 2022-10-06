#include <iostream>

#include "QueueClass.h"
using namespace std;

class Tree {
   public:
    BTNode *root;
    Tree() { root = NULL; }
    void CreateTree();
    void Preorder(BTNode *p);
    void Inorder(BTNode *p);
    void Postorder(BTNode *p);
    void Levelorder(BTNode *p);
    int Height(BTNode *p);
    void ItPreorder(BTNode *p);
    void ItInorder(BTNode *p);
    void ItPostorder(BTNode *p);
};

void Tree::CreateTree() {
    BTNode *p, *t;
    int x;
    Queue q(100);

    printf("Enter root value ");
    scanf("%d", &x);
    root = new BTNode;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty()) {
        p = q.dequeue();
        printf("Enter the left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = new BTNode;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("Enter the right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = new BTNode;
            t->data = x;
            p->rchild = t;
            t->lchild = t->rchild = NULL;
            q.enqueue(t);
        }
    }
}

// For tree traversals, we make 2n+1 recursive calls(where n = num of nodes)
// So time complexity == O(2n+1) or O(n)
// Num of activation records = 2n + 1, at a time, the call stack size is 4, ie
// (h + 2)
void Tree::Preorder(BTNode *p) {
    if (p) {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(BTNode *p) {
    if (p) {
        Preorder(p->lchild);
        printf("%d ", p->data);
        Preorder(p->rchild);
    }
}

void Tree::Postorder(BTNode *p) {
    if (p) {
        Preorder(p->lchild);
        Preorder(p->rchild);
        printf("%d ", p->data);
    }
}

void Tree::Levelorder(BTNode *p) {
    Queue q(100);
    BTNode *t;
    printf("%d\n", p->data);
    q.enqueue(p);

    while (!q.isEmpty()) {
        t = q.dequeue();
        if (t->lchild) {
            printf("%d ", t->lchild->data);
            q.enqueue(t->lchild);
        }
        if (t->rchild) {
            printf("%d ", t->rchild->data);
            q.enqueue(t->rchild);
        }
    }
}

int Tree::Height(BTNode *p) {
    int x = 0, y = 0;
    if (p == NULL) {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

void Tree::ItPreorder(BTNode *p) {}

int main() {
    Tree tr;
    tr.CreateTree();
    cout << "Preorder";
    tr.Preorder(tr.root);
    cout << endl;
    cout << "Levelorder\n";
    tr.Levelorder(tr.root);
    cout << endl;
    cout << "Height : " << tr.Height(tr.root) << endl;
    return 0;
}