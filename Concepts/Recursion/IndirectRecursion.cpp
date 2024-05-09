#include <iostream>
using namespace std;

void funB(int n);  // Declared before being called in funA, otherwise we'll get
                   // an error

void funA(int n) {
    if (n > 0) {
        printf("%d\t", n);
        funB(n - 1);
    }
}

void funB(int n) {
    if (n > 0) {
        printf("%d\t", n);
        funA(n / 2);
    }
}

int main() {
    funA(20);
    return 0;
}