#include <iostream>
#include <queue>
using namespace std;

class BTNode {
   public:
    BTNode *lchild;
    int data;
    BTNode *rchild;
    BTNode(){};
    BTNode(int data);
};

BTNode::BTNode(int data) {
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}

class Tree {
   private:
    BTNode *root;

   public:
    Tree();
    ~Tree();
    BTNode *CreateTree();
    void Preorder(BTNode *p);
    void Inorder(BTNode *p);
    void Postorder(BTNode *p);
    void Levelorder(BTNode *p);
    int Height(BTNode *p);
    int CountNodes(BTNode *p);
    void DestroyTree(BTNode *p);
};

Tree::Tree() { root = nullptr; }

Tree::~Tree() { DestroyTree(root); }

void Tree::DestroyTree(BTNode *p) {
    if (p != nullptr) {
        DestroyTree(p->lchild);
        DestroyTree(p->rchild);
        delete p;
    }
}

BTNode *Tree::CreateTree() {
    BTNode *p, *t;
    int x;
    root = new BTNode;
    cout << "Enter root data : ";
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;

    queue<BTNode *> q;
    q.emplace(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        cout << "Enter the left child of " << p->data << " ";
        cin >> x;
        if (x != -1) {
            t = new BTNode;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter the right child of " << p->data << " ";
        cin >> x;
        if (x != -1) {
            t = new BTNode;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
    return root;
}

void Tree::Preorder(BTNode *p) {
    if (p) {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(BTNode *p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(BTNode *p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

int Tree::Height(BTNode *p) {
    int l = 0;
    int r = 0;
    if (p != nullptr) {
        l = Height(p->lchild);
        r = Height(p->rchild);
        if (l > r) {
            return l + 1;
        } else {
            return r + 1;
        }
    }
    return 0;
}

int Tree::CountNodes(BTNode *p) {
    if (p != nullptr) {
        return 1 + CountNodes(p->lchild) + CountNodes(p->rchild);
    }
    return 0;
}
