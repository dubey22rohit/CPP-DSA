#include <iostream>
using namespace std;

void URLify(char *s, int len) {
    int ns = 0, i = 0, j = 0;
    for (; i < len; i++) {
        if (s[i] == ' ') {
            ++ns;
        }
    }

    int extl = len + 2 * ns;
    i = extl - 1;
    for (j = len - 1; j >= 0; --j) {
        if (s[j] != ' ') {
            s[i--] = s[j];
        } else {
            s[i--] = '0';
            s[i--] = '2';
            s[i--] = '%';
        }
    }
}

int main() {
    char str[] = "Mr John Smith    ";
    URLify(str, 13);
    cout << str;
    return 0;
    return 0;
}