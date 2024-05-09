#include <iostream>
#include <unordered_map>
using namespace std;

char repeatedCharacter(string s) {
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++) {
        mp[s[i]]++;
    }
    for (int i = 0; i < s.length() - 1; i++) {
        if ((mp[s[i]] >= 2) && (s[i] == s[i + 1])) {
            return s[i];
        }
    }
    return '\0';
}

int main() {
    string ip;
    cout << "Enter string: ";
    getline(cin, ip);
    char ans = repeatedCharacter(ip);
    printf("\nFirst duplicate char %c", ans);
    return 0;
}