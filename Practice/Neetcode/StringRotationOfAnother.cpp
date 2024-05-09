#include <iostream>
using namespace std;

bool stringRotation(string s, string t) {
    s = s + s;
    if (s.find(t) == string::npos) {
        return false;
    }
    return true;
}

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);

    bool isRotation = stringRotation(s, t);
    cout << isRotation;

    return 0;
}