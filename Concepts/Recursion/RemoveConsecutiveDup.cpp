#include <iostream>
using namespace std;

void removeConsecutiveDup(char s[]) {
    if (s[0] == '\0' || s[1] == '\0') {
        return;
    }
    if (s[0] == s[1]) {
        int i = 1;
        while (s[i] != '\0') {
            s[i - 1] = s[i];
            i++;
        }
        s[i - 1] = s[i];
        removeConsecutiveDup(s);
    } else {
        removeConsecutiveDup(s + 1);
    }
}

int main() {
    char str[100];
    cout << "Enter input string: ";
    cin >> str;
    cout << endl;
    removeConsecutiveDup(str);
    cout << str;
    return 0;
}