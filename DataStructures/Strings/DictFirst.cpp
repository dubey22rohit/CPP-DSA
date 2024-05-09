#include <iostream>
using namespace std;

char *DictFirst(char *a, char *b) {
    int i = 0;
    int j = 0;
    while (a[i] != '\0' || b[j] != '\0') {
        if (a[i] > b[j]) {
            return b;
        } else if (a[i] < b[j]) {
            return a;
        } else {
            i++;
            j++;
        }
    }
    return "Both strings are equal";
}

int main() {
    char a[] = "Margrit";
    char b[] = "Morgott";
    char *ans;
    ans = DictFirst(a, b);
    cout << ans;
    return 0;
}