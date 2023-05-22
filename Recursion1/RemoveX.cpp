#include <iostream>
using namespace std;

int length(char input[]) {
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        len++;
    }
    return len;
}

void removeXHelper(char input[], int ci) {
    if (input[ci] == '\0') {
        return;
    }

    removeXHelper(input, ci + 1);

    if (input[ci] == 'x') {
        int len = length(input);
        int i;
        for (i = ci + 1; i < len; i++) {
            input[i - 1] = input[i];
        }
        input[i - 1] = '\0';
    }
}
void removeX(char input[]) { return removeXHelper(input, 0); }

int main() {
    int n;
    cin >> n;
    char input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    removeX(input);
    for (int i = 0; i < n; i++) {
        cout << input[i];
    }
    return 0;
}