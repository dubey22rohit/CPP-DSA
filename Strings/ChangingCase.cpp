#include <iostream>
using namespace std;

void changeToLower(char *c) {
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] >= 65 && c[i] <= 90) {
            // Is upper case, A->65 Z->90
            c[i] += 32;
        } else if (c[i] >= 'a' && c[i] <= 122) {
            // Is lower case, a->97 z->122
            // Used 'a' and 122 in the condition to show various possibilities
            // that we can use to compare
            c[i] -= 32;
        }
    }
}

int main() {
    char A[] = "WeLcOmE";
    changeToLower(A);
    cout << A;
    return 0;
}