#include <iostream>
using namespace std;

void URLify(char *str, int len) {
    int ns = 0;
    int i = 0, j = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == ' ') {
            ++ns;
        }
    }

    int extl = len + 2 * ns;
    i = extl - 1;
    for (j = len - 1; j >= 0; j--) {
        if (str[j] != ' ') {
            str[i--] = str[j];
        } else {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }
}

int main() {
    char str[] = "Mr Johnny Smith    ";
    URLify(str, 15);
    cout << str;
    return 0;
}