#include <iostream>
using namespace std;

void Duplicates(char *c) {
    int H = 0, a = 0;
    for (int i = 0; c[i] != '\0'; i++) {
        a = 1;
        a = a << (c[i] - 97);
        if ((a & H) > 0) {
            printf("%c is a duplicate\n", c[i]);
        } else {
            H = a | H;
        }
    }
}

int main() {
    char c[] = "finding";
    Duplicates(c);
    return 0;
}