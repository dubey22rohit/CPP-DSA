#include <string>
class TrieNode {
   public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        this->children = new TrieNode*[26];
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            delete[] children[i];
        }
        delete[] children;
    }
};

// Incomplete, TODO
class Trie {
    TrieNode* root;

   public:
    int count;
    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    void insertWord(std::string word) {
        if (insertWordHelper(root, word)) {
            this->count++;
        }
    }
    bool insertWordHelper(TrieNode* root, std::string word) {}
};