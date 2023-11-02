#include <iostream>
using namespace std;

class TrieNode {
   public:
    TrieNode* children[26];
    bool isLeaf = false;
};

class Trie {
    TrieNode* root;

   public:
    Trie() { this->root = new TrieNode(); }

    void insert(string word) {
        TrieNode* temp = root;

        for (char c : word) {
            if (!temp->children[c - 'a']) {
                temp->children[c - 'a'] = new TrieNode();
            }
            temp = temp->children[c - 'a'];
        }
        temp->isLeaf = true;
    }

    bool search(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            if (!temp->children[c - 'a']) {
                return false;
            }
            temp = temp->children[c - 'a'];
        }
        return temp->isLeaf;
    }

    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (char c : prefix) {
            if (!temp->children[c - 'a']) {
                return false;
            }
            temp = temp->children[c - 'a'];
        }
        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("procoder");
    cout << obj->search("procoder") << endl;
    cout << obj->startsWith("proc") << endl;

    return 0;
}