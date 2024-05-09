class TrieNode {
   public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode*[26];
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        this->isTerminal = false;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            delete[] children[i];
        }
        delete[] children;
    }
};