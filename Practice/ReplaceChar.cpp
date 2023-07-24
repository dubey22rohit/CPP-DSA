#include <iostream>
using namespace std;

void replaceChar(char str[], char c1, char c2) {
    if (str[0] == '\0') {
        return;
    }
    if (str[0] == c1) {
        str[0] = c2;
        replaceChar(str + 1, c1, c2);
    } else {
        replaceChar(str + 1, c1, c2);
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