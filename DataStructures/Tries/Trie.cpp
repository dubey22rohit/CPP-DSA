#include <string>
#include <vector>

#include "TrieNode.h"
using namespace std;

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWordHelper(TrieNode *root, string word) {
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        int index = word[0] - 'a';  //'a' - 'a' = 0, 'b' - 'a' = 1
        TrieNode *child;
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWordHelper(child, word.substr(1));
    }

    bool searchWordHelper(TrieNode *root, string word) {
        if (word.size() == 0) {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            return false;
        }
        return searchWordHelper(child, word.substr(1));
    }

    void deleteWordHelper(TrieNode *root, string word) {
        if (word.size() == 0) {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            // Word not found
            return;
        }

        deleteWordHelper(child, word.substr(1));

        // Remove child node if it is useless
        if (!child->isTerminal) {
            for (int i = 0; i < 26; i++) {
                if (child->children[i] != nullptr) {
                    return;
                }
            }
            delete child;
            root->children[index] = nullptr;
        }
    }

    void insertWord(string word) {
        if (insertWordHelper(root, word)) {
            this->count++;
        }
    }
    bool searchWord(string word) { return searchWordHelper(root, word); }
    void deleteWord(string word) { deleteWordHelper(root, word); }
    bool patternMatching(vector<string> vect, string pattern) {
        for (int i = 0; i < vect.size(); i++) {
            string word = vect[i];
            for (int j = 0; j < word.length(); j++) {
                insertWord(word.substr(j));
            }
        }
        return searchWord(pattern);
    }
};