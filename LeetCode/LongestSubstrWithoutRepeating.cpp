#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hm;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (hm.find(s[i]) != hm.end()) {
            ans = 0;
        }
        hm[s[i]]++;
        ans += 1;
    }
    return ans;
}

int main() {
    string ip;
    getline(cin, ip);
    cout << lengthOfLongestSubstring(ip);
    return 0;
}