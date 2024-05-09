#include <iostream>
using namespace std;

int length(char s[]) {
    if (s[0] == '\0') {
        return 0;
    }
    return 1 + length(s + 1);
}

int main() {
    char str[100];
    cin.get(str, 100);

    int l = length(str);
    cout << l << endl;

    return 0;
}