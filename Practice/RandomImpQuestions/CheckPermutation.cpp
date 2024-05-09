#include <iostream>
#include <unordered_map>
using namespace std;

bool checkPermutation(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    unordered_map<char, int> hm;
    for (int i = 0; i < s.length(); i++) {
        hm[s[i]]++;
    }

    for (int i = 0; i < t.length(); i++) {
        hm[t[i]]--;
        if (hm[t[i]] < 0) {
            return false;
        }
    }

    unordered_map<char, int>::iterator it = hm.begin();
    while (it != hm.end()) {
        if (it->second != 0) {
            return false;
        }
        it++;
    }
    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << "Are permutations of each other? " << checkPermutation(s, t);
    return 0;
}