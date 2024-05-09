#include <iostream>
#include <map>
using namespace std;

string compressString(string s) {
    if (s.length() == 0) {
        return "";
    }
    int c = 0;
    string ans, ns;
    int i = 0;
    for (i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            c++;
        } else {
            ns = c == 0 ? "" : to_string(c + 1);
            ans += s[i] + ns;
            c = 0;
        }
    }
    ns = c == 0 ? "" : to_string(c + 1);
    ans += s[i] + ns;
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << "Compressed string: " << compressString(s);
    return 0;
}