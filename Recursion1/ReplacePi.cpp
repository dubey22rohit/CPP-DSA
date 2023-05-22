#include <iostream>
using namespace std;

int length(char input[]) {
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        len++;
    }
    return len;
}

void replacePiHelper(char input[], int ci) {
    if (input[ci] == '\0' || input[ci + 1] == '\0') {
        return;
    }
    if (input[ci] == 'p' && input[ci + 1] == 'i') {
        int len = length(input);
        input[len + 2] = '\0';
        for (int i = len - 1; i >= ci + 2; i--) {
            input[i + 2] = input[i];
        }
        input[ci] = '3';
        input[ci + 1] = '.';
        input[ci + 2] = '1';
        input[ci + 3] = '4';
        replacePiHelper(input, ci + 4);
    } else {
        replacePiHelper(input, ci + 1);
    }
}

void replacePi(char input[]) { replacePiHelper(input, 0); }

int main() {
    int n;
    cin >> n;
    char input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    replacePi(input);
    for (int i = 0; i < n; i++) {
        cout << input[i];
    }
    return 0;
}