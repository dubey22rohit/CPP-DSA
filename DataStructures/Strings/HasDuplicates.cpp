#include <iostream>
using namespace std;

char *StringDuplicates(char *c) {
    // Only for lowercase letters;
    int *h;
    char *ans;
    h = new int[26];
    ans = new char[26];
    for (int i = 0; i < 26; i++) {
        h[i] = 0;
    }

    for (int i = 0; c[i] != '\0'; i++) {
        h[c[i] - 97]++;
    }

    int k = 0;
    for (int i = 0; i < 26; i++) {
        if (h[i] > 1) {
            ans[k++] = i + 97;
        }
    }
    return ans;
}

int main() {
    char str[] = "Caelidaeli";
    char *ans;
    ans = StringDuplicates(str);
    cout << ans;
    delete[] ans;
    return 0;
}