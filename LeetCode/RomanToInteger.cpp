#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int checkException(char c1, char c2) {
    if (c1 == 'I') {
        if (c2 == 'V') {
            return 4;
        } else if (c2 == 'X') {
            return 9;
        }
    } else if (c1 == 'X') {
        if (c2 == 'L') {
            return 40;
        } else if (c2 == 'C') {
            return 90;
        }
    } else if (c1 == 'C') {
        if (c2 == 'D') {
            return 400;
        } else if (c2 == 'M') {
            return 900;
        }
    }
    return -1;
}

int romanToInt(string s) {
    unordered_map<char, int> hm;
    hm['I'] = 1;
    hm['V'] = 5;
    hm['X'] = 10;
    hm['L'] = 50;
    hm['C'] = 100;
    hm['D'] = 500;
    hm['M'] = 1000;

    int ans = 0;
    int i = 0;
    while (i < s.length() - 1) {
        int ex = checkException(s[i], s[i + 1]);
        if (ex != -1) {
            ans += ex;
            i += 2;
        } else {
            ans += hm[s[i]];
            i++;
        }
    }
    if (i != s.length()) {
        ans += hm[s[s.length() - 1]];
    }

    return ans;
}

int main() {
    string s;
    getline(cin, s);
    int ans = romanToInt(s);
    cout << ans;
    return 0;
}