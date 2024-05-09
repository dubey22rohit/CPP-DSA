#include <iostream>
using namespace std;

bool IsOneAway(string s, string t) {
    int slen = s.length();
    int tlen = t.length();
    int i = 0, j = 0;
    int count = 0;
    if (abs(slen - tlen) > 1) {
        return false;
    }
    while (i < slen && j < tlen) {
        if (count > 1) {
            return false;
        }
        if (s[i] != t[j]) {
            count++;
            if (slen > tlen) {
                i++;
                continue;
            } else if (slen < tlen) {
                j++;
                continue;
            }
        }
        i++;
        j++;
    }

    if (i != slen && abs(i - slen) > 1) {
        return false;
    }
    if (j != tlen && floor(abs(j - tlen)) > 1) {
        return false;
    }

    return true;
}

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    bool oneAway = IsOneAway(s, t);
    cout << oneAway;
    return 0;
}