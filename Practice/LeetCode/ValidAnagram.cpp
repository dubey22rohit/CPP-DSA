#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++) {
        mp[s[i]]++;
    }
    for (int i = 0; i < t.length(); i++) {
        mp[t[i]]--;
        if (mp[t[i]] < 0) {
            return false;
        }
    }

    unordered_map<char, int>::iterator it = mp.begin();

    while (it != mp.end()) {
        if (it->second != 0) {
            return false;
        }
        it++;
    }
    return true;
}

int main() {
    string s = "angered";
    string t = "enraged";
    cout << "Is t an anagram of s? :" << isAnagram(s, t);
    return 0;
}