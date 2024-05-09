#include <iostream>
#include <unordered_map>
using namespace std;

bool palindromePermutation(string s) {
    unordered_map<char, int> hm;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            hm[s[i]]++;
        }
    }

    unordered_map<char, int>::iterator it = hm.begin();
    int flag = 0;
    while (it != hm.end()) {
        if (it->second % 2 != 0 && flag == 1) {
            return false;
        } else if (it->second % 2 != 0 && flag != 1) {
            flag = 1;
        }
        ++it;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    cout << "Palindrome Permutation: " << palindromePermutation(s);
    return 0;
}