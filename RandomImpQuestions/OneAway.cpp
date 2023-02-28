#include <iostream>
#include <unordered_map>
using namespace std;

string greaterLength(string s, string t) {
    if (s.length() > t.length()) {
        return s;
    } else {
        return t;
    }
}

bool oneEditAway(string s, string t) {
    if (abs(s.length() - t.length()) > 1) {
        return false;
    }
    unordered_map<char, int> hm;
    string gt = greaterLength(s, t);
    for (int i = 0; i < gt.length(); i++) {
        hm[gt[i]]++;
    }
}

int main() { return 0; }