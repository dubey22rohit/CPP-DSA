#include <iostream>
using namespace std;

// PROBLEM : Implement an algorithm to determine if a string has all unique
// characters. What if you cannot use additional DS?

// Checking if a string has all unique characters, by using an additional
// DS(Array in this case)
bool IsUnique(char *s) {
    int *H;
    H = new int[25];
    int k = 0;

    for (int i = 0; i < 25; i++) {
        H[i] = 0;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        H[s[i] - 97]++;
    }

    for (int i = 0; i < 25; i++) {
        if (H[i] > 1) {
            return false;
        }
    }
    return true;
}

// Checking if a string has all unique characters, without using any additional
// DS.(Using bit masking and merging)
bool IsUniqueBits(char *s) {
    int H = 0, a = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        a = 1;
        a = a << (s[i] - 97);
        if ((H & a) > 0) {
            return false;
        } else {
            H = H | a;
        }
    }
    return true;
}

int main() {
    char *s = "nokstella";
    char *t = "caelid";
    cout << "Has unique characters? " << IsUnique(s) << endl;
    cout << "Has unique characters? " << IsUnique(t) << endl;
    cout << "Has unique characters using bits? " << IsUniqueBits(s) << endl;
    cout << "Has unique characters? using bits? " << IsUniqueBits(t) << endl;

    return 0;
}