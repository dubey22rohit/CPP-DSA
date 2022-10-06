#include <iostream>
using namespace std;

char *ReverseString(char *c) {
    int i;
    while (c[i] != '\0') {
        i++;
    }
    i -= 1;
    char *rev = new char[i];
    int k = 0;
    for (; i >= 0; i--) {
        rev[k++] = c[i];
    }
    rev[k] = '\0';
    return rev;
}

void swap(char *x, char *y) {
    char t;
    t = *x;
    *x = *y;
    *y = t;
}

void ReverseString2(char *c) {
    int i = 0;
    int j = 0;
    while (c[j] != '\0') {
        j++;
    }
    j -= 1;
    while (i < j) {
        swap(&c[i], &c[j]);
        i++;
        j--;
    }
}

int main() {
    // char str[] = "Godrick the fallen";
    // char *ans;
    // ans = ReverseString(str);
    // cout << ans;

    cout << endl;

    char str2[] = "Raya Lucaria Academy";
    ReverseString2(str2);

    cout << str2;
    return 0;
}