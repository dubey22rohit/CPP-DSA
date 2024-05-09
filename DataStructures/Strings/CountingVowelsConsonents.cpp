#include <iostream>
using namespace std;

int CountVowels(char *c) {
    int count = 0;
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' ||
            c[i] == 'u' || c[i] == 'A' || c[i] == 'E' || c[i] == 'I' ||
            c[i] == 'O' || c[i] == 'U') {
            count++;
        }
    }
    return count;
}

int CountConsonents(char *c) {
    int count = 0;
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' ||
            c[i] == 'u' || c[i] == 'A' || c[i] == 'E' || c[i] == 'I' ||
            c[i] == 'O' || c[i] == 'U') {
            continue;
        } else if ((c[i] >= 65 && c[i] <= 90) || (c[i] >= 97 && c[i] <= 122)) {
            count++;
        }
    }
    return count;
}

int CountWords(char *c) {
    int wCount = 0;
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] == ' ' && c[i - 1] != ' ') {
            // c[i - 1] != ' ' No extra spaces
            wCount++;
        }
    }
    return wCount + 1;
}

int main() {
    char A[] = "How are you";
    int vCount = CountVowels(A);
    int cCount = CountConsonents(A);
    int wCount = CountWords(A);
    cout << "Number of vowels : " << vCount << endl;
    cout << "Number of consonents : " << cCount << endl;
    cout << "Number of words : " << wCount << endl;
    return 0;
}