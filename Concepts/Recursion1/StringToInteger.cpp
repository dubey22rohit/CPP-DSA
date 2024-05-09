#include <cmath>
#include <iostream>
using namespace std;

int length(char input[]) {
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        len++;
    }
    return len;
}

int stringToNumberHelper(char input[], int ci, int len) {
    if (input[ci] == '\0') {
        return 0;
    }
    int smallAns = stringToNumberHelper(input, ci + 1);
    int currNumber = input[ci] - '0';
    return smallAns + (currNumber * pow(10, len));
}

int stringToNumber(char input[]) {
    int len = length(input);
    return stringToNumberHelper(input, 0, len - 1);
}

int main() {
    int n;
    cin >> n;
    char input[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    cout << stringToNumber(input);

    return 0;
}