#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> hm1, hm2;
    for (int i = 0; i < s.length(); i++) {
        if (hm1[s[i]] && hm1[s[i]] != t[i]) {
            return false;
        }
        if (hm2[t[i]] && hm2[t[i]] != s[i]) {
            return false;
        }
        hm1[s[i]] = t[i];
        hm2[t[i]] = s[i];
    }
    return true;
}

int main() {
    bool ans = isIsomorphic("badc", "baba");
    cout << ans;
    return 0;
}