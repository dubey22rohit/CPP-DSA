#include <iostream>
using namespace std;

void replaceChar(char s[], char ch, char rp) {
    if (s[0] == '\0') {
        return;
    }
    if (s[0] == ch) {
        s[0] = rp;
        replaceChar(s + 1, ch, rp);
    } else {
        replaceChar(s + 1, ch, rp);
    }
}

int main() {
    char str[100];
    char ch;
    char rp;

    cout << "Enter string: ";
    cin >> str;
    cout << endl;

    cout << "Enter char to replace : ";
    cin >> ch;
    cout << endl;

    cout << "Enter char to replace with : ";
    cin >> rp;
    cout << endl;

    replaceChar(str, ch, rp);
    cout << str << endl;
    return 0;
}