#include <iostream>
using namespace std;

bool isValid(char *c) {
    for (int i = 0; c[i] != '\0'; i++) {
        if (!(c[i] >= 65 && c[i] <= 90) && !(c[i] >= 97 && c[i] <= 122) &&
            !(c[i] >= 48 && c[i] <= 57)) {
            return false;
        }
    }
    return true;
}

int main() {
    char *username = "Rohit1234";
    cout << "isValid ? " << isValid(username);
    return 0;
}