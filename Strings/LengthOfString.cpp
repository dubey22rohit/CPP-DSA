#include <iostream>
using namespace std;

int length(char *c) {
    int count = 0;
    for (int i = 0; c[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main() {
    char name[] = "John Cena";

    cout << "Length of string : " << length(name);
    return 0;
}