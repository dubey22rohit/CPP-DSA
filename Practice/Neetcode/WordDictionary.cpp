#include <iostream>
using namespace std;

class TrieNode {
   public:
    TrieNode* children[26];
    bool isLeaf = false;

    TrieNode() {
        this->isLeaf = false;
        memset(this->children, NULL, sizeof(TrieNode*) * 26);
    }
};

class WordDictionary {
    TrieNode* root;

   public:
    WordDictionary() { this->root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            if (!temp->children[c - 'a']) {
                temp->children[c - 'a'] = new TrieNode();
            }
            temp = temp->children[c - 'a'];
        }
        temp->isLeaf = true;
        return;
    }

    //! Search function not complete
    //! does not support search of words like .ab, b.., etc
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
};

int main() {
    WordDictionary* wordDictionary = new WordDictionary();
    wordDictionary->addWord("bad");
    wordDictionary->addWord("chad");
    wordDictionary->addWord("mad");

    cout << wordDictionary->search("pad") << endl;
    cout << wordDictionary->search("bad") << endl;
    cout << wordDictionary->search(".ad") << endl;
    cout << wordDictionary->search("b..") << endl;

    return 0;
}