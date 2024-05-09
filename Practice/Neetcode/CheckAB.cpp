#include <iostream>
using namespace std;

bool checkAB(string input, int si) {
    if (input[si] == '\0') {
        return true;
    }
    if (input[si] != 'a') {
        return false;
    }
    if (input[si + 1] != '\0' && input[si + 2] != '\0') {
        if (input[si + 1] == 'b' && input[si + 2] == 'b') {
            return checkAB(input, si + 3);
        }
    }
    return checkAB(input, si + 1);
}

int main() {
    string input;
    getline(cin, input);

    bool ans = checkAB(input, 0);
    cout << ans;

    return 0;
}