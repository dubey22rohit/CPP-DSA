#include <iostream>
using namespace std;

bool CheckAnagram(char *a, char *b, int lenA, int lenB) {
    int *H = new int[26];
    if (lenA != lenB) {
        return false;
    }
    for (int i = 0; a[i] != '\0'; i++) {
        H[a[i] - 97]++;
    }
    for (int i = 0; b[i] != '\0'; i++) {
        H[b[i] - 97]--;
        if (H[b[i] - 97] < 0) {
            return false;
        }
    }
    delete[] H;
    return true;
}

bool CheckAnagramUsingBits(char *c, char *d, int lenC, int lenD) {
    // Won't work if there are duplicate characters in a string, as we cannot
    // store a value more than 1 in 1 bit;
    if (lenC != lenD) {
        return false;
    }
    int H = 0, a = 0;
    for (int i = 0; c[i] != '\0'; i++) {
        a = 1;
        a = a << (c[i] - 97);
        H = H | a;
    }

    for (int i = 0; d[i] != '\0'; i++) {
        a = 1;
        a = a << (d[i] - 97);
        if ((a & H) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    char a[] = "verbose";  // Repeating charcters
    char b[] = "observe";

    char c[] = "decimal";
    char d[] = "medical";

    int lenA = sizeof(a) / sizeof(a[0]);
    int lenB = sizeof(b) / sizeof(b[0]);

    int lenC = sizeof(c) / sizeof(c[0]);
    int lenD = sizeof(d) / sizeof(d[0]);

    cout << "Strings anagram ? " << CheckAnagram(a, b, lenA, lenB) << endl;
    cout << "Strings anagram ? " << CheckAnagram(c, d, lenC, lenD) << endl;

    // Using Bit Masking and Merging
    cout << "Strings anagram using bits ? "
         << CheckAnagramUsingBits(c, d, lenC, lenD) << endl;

    return 0;
}
