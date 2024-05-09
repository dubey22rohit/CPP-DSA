#include <iostream>
using namespace std;

int length(char input[]) {
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        len++;
    }
    return len;
}
bool checkPalindrome(char input[], int s, int e) {
    if (input[0] == '\0' || input[1] == '\0') {
        return true;
    }
    if (s >= e) {
        return true;
    }
    bool smallAns = false;
    if (input[s] == input[e]) {
        smallAns = true;
    }
    return smallAns && checkPalindrome(input, s + 1, e - 1);
}
bool checkPalindrome(char input[]) {
    int s = 0, e = length(input) - 1;
    return checkPalindrome(input, s, e);
}

int main() {
    int n;
    cin >> n;
    char input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cout << checkPalindrome(input);
    return 0;
}