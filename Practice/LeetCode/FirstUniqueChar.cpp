#include <iostream>
#include <unordered_map>
using namespace std;

int firstUniqueChar(string s) {
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++) {
        mp[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++) {
        if (mp[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    string ip;
    cout << "Enter string: ";
    getline(cin, ip);
    int ans = firstUniqueChar(ip);
    printf("\nFirst unique char %c at index %d", ip[ans], ans);
    return 0;
}