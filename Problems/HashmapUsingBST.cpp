#include <iostream>
#include <queue>

#include "BTNode.cpp"
using namespace std;

template <class K, class V>
class BSTNode {
   public:
    K key;
    V value;
    BSTNode<K, V>* lchild;
    BSTNode<K, V>* rchild;

    BSTNode() {
        lchild = nullptr;
        rchild = nullptr;
    }

    BSTNode(K key, V value) {
        this->key = key;
        this->value = value;
        lchild = nullptr;
        rchild = nullptr;
    }

    ~BSTNode() {
        delete lchild;
        delete rchild;
    }
};
template <class K, class V>
class HashMapUsingBST {
   public:
    BSTNode<K, V>* root;
    HashMapUsingBST() { root = nullptr; }

    void printHashMap() {
        BSTNode<K, V>* cn;
        queue<BSTNode<K, V>*> pn;
        pn.emplace(root);
        while (!pn.empty()) {
            cn = pn.front();
            pn.pop();
            cout << "Parent: " << cn->key << ": " << cn->value << "\n";
            if (cn->lchild) {
                cout << "L: " << cn->lchild->key << ": " << cn->lchild->value;
                pn.emplace(cn->lchild);
            }

            if (cn->rchild) {
                cout << "L: " << cn->rchild->key << ": " << cn->rchild->value;
                pn.emplace(cn->rchild);
            }

            cout << endl;
        }
    }

    void insert(K iKey, V iValue) {
        BSTNode<K, V>* nn;
        if (this->root == nullptr) {
            nn = new BSTNode<K, V>(iKey, iValue);
            root = nn;
            cout << "CURRENT ROOT " << root->key << ": " << root->value << endl;
            return;
        }
        BSTNode<K, V>* rp = this->root;
        cout << "CURRENT ROOT POINTER " << rp->key << ": " << rp->value;
        while (rp->lchild != nullptr || rp->rchild != nullptr) {
            cout << "ENTERED WHILE";
            if (iKey < rp->key) {
                rp = rp->lchild;
            } else if (iKey > rp->key) {
                rp = rp->rchild;
            } else {
                rp->value = iValue;
            }
        }

        nn = new BSTNode<K, V>(iKey, iValue);
        if (iKey < rp->key) {
            rp->lchild = nn;
        } else {
            rp->rchild = nn;
        }
    }

    V search(K sKey) {
        BSTNode<K, V>* rp = root;
        while (sKey != rp->key) {
            if (sKey < rp->key) {
                rp = rp->lchild;
            } else if (sKey > rp->key) {
                rp = rp->rchild;
            } else {
                return rp->value;
            }
        }
    }

    // V delete(K dKey) {}
};

int main() {
    HashMapUsingBST<int, char> hm;
    hm.insert(20, 'a');
    hm.insert(10, 'b');
    // hm.insert(30, 'c');
    // hm.insert(5, 'd');
    // hm.insert(15, 'e');
    // hm.insert(25, 'f');
    // hm.insert(35, 'g');

    // hm.printHashMap();
    return 0;
}