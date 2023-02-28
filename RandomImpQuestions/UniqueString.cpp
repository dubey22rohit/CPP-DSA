#include <iostream>
#include <unordered_map>
using namespace std;

bool hasUniqueCharacters(string s) {
    if (s.length() == 0) {
        return true;
    }
    unordered_map<char, int> hm;
    for (int i = 0; i < s.length(); i++) {
        hm[s[i]]++;
    }

    unordered_map<char, int>::iterator it = hm.begin();
    while (it != hm.end()) {
        if (it->second > 1) {
            return false;
        }
        ++it;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << "Unique?: " << hasUniqueCharacters(s);
    return 0;
}