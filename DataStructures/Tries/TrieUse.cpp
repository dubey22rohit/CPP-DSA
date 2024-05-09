#include <iostream>

#include "Trie.cpp"
using namespace std;

int main() {
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout << t.searchWord("and") << endl;

    t.deleteWord("and");

    cout << t.searchWord("and") << endl;
    return 0;
}