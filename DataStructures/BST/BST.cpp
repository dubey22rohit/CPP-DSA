#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class Node {
   public:
    Node* lchild;
    T data;
    Node* rchild;

    Node() {
        this->lchild = nullptr;
        this->rchild = nullptr;
    }
    Node(T data) {
        this->lchild = nullptr;
        this->data = data;
        this->rchild = nullptr;
    }
};

template <typename T>
class BST {
   private:
    Node<T>* root;

   public:
    BST() { root = nullptr; }
    Node<T>* Create() {
        T x;
        cout << "Enter the root data : ";
        cin >> x;
        Node<T>* root = new Node<T>(x);
        Node<T>* nn;
        queue<Node<T>*> q;
        q.emplace(root);
        while (!q.empty()) {
            Node<T>* pn = q.front();
            q.pop();
            cout << "Enter the left child of: " << pn->data << ": ";
            cin >> x;
            if (x != -1) {
                nn = new Node<T>(x);
                if (x >= pn->data) {
                    cout << "Left child cannot be greater than or equal to the "
                            "parent node data in a BST\n";
                    return nullptr;
                } else {
                    pn->lchild = nn;
                }
                q.emplace(nn);
            }

            cout << "Enter the right child of: " << pn->data << ": ";
            cin >> x;
            if (x != -1) {
                nn = new Node<T>(x);
                if (x <= pn->data) {
                    cout << "Right child cannot be smaller than or equal to "
                            "the parent node data in a BST\n";
                    return nullptr;
                } else {
                    pn->rchild = nn;
                }
                q.emplace(nn);
            }
        }
        return root;
    }
    void Insert(Node<T>* root, T ele) {
        Node<T>*nn, *p, *q;
        if (ele == -1) {
            return;
        }
        if (root == nullptr) {
            nn = new Node<T>(ele);
            root = nn;
            return;
        }
        p = root;
        q = root;
        while (p != nullptr) {
            q = p;
            if (ele < p->data) {
                p = p->lchild;
            } else if (ele > p->data) {
                p = p->rchild;
            } else {
                cout << "Element already exists";
                return;
            }
        }
        nn = new Node<T>(ele);
        if (ele < q->data) {
            q->lchild = nn;
        } else {
            q->rchild = nn;
        }
    }
    Node<T>* Remove(Node<T>* root, T ele) {
        Node<T>*rn, *p = nullptr, *q = nullptr;
        p = root;
        while (p != nullptr) {
            if (ele < p->data) {
                q = p;
                p = p->lchild;
            } else if (ele > p->data) {
                q = p;
                p = p->rchild;
            } else {
                break;
            }
        }
        rn = new Node<T>(p->data);
        if (ele < q->data) {
            q->lchild = nullptr;
        } else {
            q->rchild = nullptr;
        }
        return rn;
    }
    Node<T>* Search(Node<T>* root, T ele) {
        if (root == nullptr) {
            return nullptr;
        }
        Node<T>* p = root;
        while (p != nullptr) {
            if (p->data == ele) {
                return p;
            } else if (ele < p->data) {
                p = p->lchild;
            } else {
                p = p->rchild;
            }
        }
        return nullptr;
    }
    void Preorder(Node<T>* root) {
        if (root) {
            cout << root->data << " ";
            Preorder(root->lchild);
            Preorder(root->rchild);
        }
    }
    void Inorder(Node<T>* root) {
        if (root) {
            Inorder(root->lchild);
            cout << root->data << " ";
            Inorder(root->rchild);
        }
    }
    void Postorder(Node<T>* root) {
        if (root) {
            Postorder(root->lchild);
            Postorder(root->rchild);
            cout << root->data << " ";
        }
    }
    void Levelorder(Node<T>* root) {
        Node<T>* pn;
        queue<Node<T>*> q;
        q.emplace(root);
        while (!q.empty()) {
            pn = q.front();
            q.pop();
            cout << pn->data << " ";
            if (pn->lchild != nullptr) {
                q.emplace(pn->lchild);
            }
            if (pn->rchild != nullptr) {
                q.emplace(pn->rchild);
            }
        }
    }
    int Height(Node<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        int lh = 1 + Height(root->lchild);
        int rh = 1 + Height(root->rchild);

        return lh > rh ? lh : rh;
    }
    int Count(Node<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + Count(root->lchild) + Count(root->rchild);
    }
    Node<T>* BSTFromPreorder(vector<int>& pre) {}
};

int main() {
    BST<int> root;
    Node<int>* bst = root.Create();

    cout << "Preorder: ";
    root.Preorder(bst);
    cout << endl;

    cout << "Inorder: ";
    root.Inorder(bst);
    cout << endl;

    cout << "Postorder: ";
    root.Postorder(bst);
    cout << endl;

    cout << "Levelorder: ";
    root.Levelorder(bst);
    cout << endl;

    cout << "Height: ";
    cout << root.Height(bst);
    cout << endl;

    cout << "Count: ";
    cout << root.Count(bst);
    cout << endl;

    cout << "Insert 1 ";
    root.Insert(bst, 1);
    cout << endl;

    cout << "Insert 27 ";
    root.Insert(bst, 27);
    cout << endl;

    cout << "Preorder after insert: ";
    root.Preorder(bst);
    cout << endl;

    cout << "Height after insert: ";
    cout << root.Height(bst);
    cout << endl;

    cout << "Count after insert: ";
    cout << root.Count(bst);
    cout << endl;

    cout << "Search: ";
    cout << root.Search(bst, 1)->data;
    cout << endl;

    cout << "Remove: ";
    cout << root.Remove(bst, 35)->data;
    cout << endl;

    cout << "Preorder after removal: ";
    root.Preorder(bst);
    cout << endl;

    return 0;
}