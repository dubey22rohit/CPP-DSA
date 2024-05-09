#include <iostream>
using namespace std;

void replaceChar(char s[], char c1, char c2) {
    if (s[0] == '\0') {
        return;
    }
    if (s[0] == c1) {
        s[0] = c2;
        replaceChar(s + 1, c1, c2);
    } else {
        replaceChar(s + 1, c1, c2);
    }
}

int main() {
    char str[100];
    cin.get(str, 100);
    char c1, c2;
    cin >> c1 >> c2;

    replaceChar(str, c1, c2);
    cout << str;

    return 0;
}