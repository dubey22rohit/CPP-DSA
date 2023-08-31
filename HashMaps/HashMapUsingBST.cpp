#include <iostream>
#include <string>
using namespace std;

template <class K, class V>
class BTNode {
   public:
    BTNode* lchild;
    K key;
    V value;
    BTNode* rchild;
    BTNode() { this->lchild = this->rchild = nullptr; }
    BTNode(K key, V value) {
        this->lchild = nullptr;
        this->key = key;
        this->value = value;
        this->rchild = nullptr;
    }
};

template <class K, class V>
class HashMapUsingBST {
   private:
    BTNode<K, V>* root;

   public:
    HashMapUsingBST() { root = nullptr; }
    BTNode<K, V>* Insertr(BTNode<K, V>* p, K key, V value) {
        BTNode<K, V>* t;
        if (p == NULL) {
            t = new BTNode<K, V>;
            t->key = key;
            t->value = value;
            t->lchild = nullptr;
            t->rchild = nullptr;
            return t;
        }

        if (key < p->key) {
            p->lchild = Insertr(p->lchild, key, value);
        } else if (key > p->key) {
            p->rchild = Insertr(p->rchild, key, value);
        }
        return p;
    }
    BTNode<K, V>* Insert(BTNode<K, V>* p, K key, V value) {
        BTNode<K, V>* t = NULL;
        BTNode<K, V>* nn;
        if (p == NULL) {
            t = p;
        }
        while (p != nullptr) {
            t = p;
            if (key < p->key) {
                p = p->lchild;
            } else if (key > p->key) {
                p = p->rchild;
            }
        }
        nn = new BTNode<K, V>;
        nn->key = key;
        nn->value = value;
        nn->lchild = nullptr;
        nn->rchild = nullptr;
        if (nn->key < t->key) {
            t->lchild = nn;
        } else if (nn->key > t->key) {
            t->rchild = nn;
        }
        return p;
    }
    BTNode<K, V>* Search(K key);
    BTNode<K, V>* Delete(K key);
    void Preorder(BTNode<K, V>* p) {
        if (p) {
            cout << "Key: " << p->key << ", Value : " << p->value << "\n";
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }
    void Inorder(BTNode<K, V>* p) {
        if (p) {
            Inorder(p->lchild);
            cout << "Key: " << p->key << ", Value : " << p->value << "\n";
            Inorder(p->rchild);
        }
    }

    void Postorder(BTNode<K, V>* p) {
        if (p) {
            Postorder(p->lchild);
            Postorder(p->rchild);
            cout << "Key: " << p->key << ", Value : " << p->value << "\n";
        }
    }
};

int main() {
    HashMapUsingBST<char, int> hm;
    BTNode<char, int>* bst = NULL;
    bst = hm.Insertr(bst, 'a', 4);
    bst = hm.Insertr(bst, 'b', 9);
    bst = hm.Insertr(bst, 'c', 16);
    bst = hm.Insertr(bst, 'd', 25);
    bst = hm.Insertr(bst, 'e', 36);
    bst = hm.Insertr(bst, 'f', 49);
    bst = hm.Insertr(bst, 'g', 64);

    cout << "Preorder : \n";
    hm.Preorder(bst);
    cout << "\n";

    cout << "Inorder : \n";
    hm.Inorder(bst);
    cout << "\n";

    cout << "Postorder : \n";
    hm.Postorder(bst);
    cout << "\n";

    return 0;
}
