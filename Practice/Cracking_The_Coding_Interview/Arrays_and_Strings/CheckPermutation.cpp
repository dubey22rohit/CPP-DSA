#include <iostream>
using namespace std;

bool CheckPermutation(char *s1, char *s2) {
    int *H;
    H = new int[25];

    for (int i = 0; s1[i] != '\0'; i++) {
        H[s1[i] - 97]++;
    }

    for (int i = 0; s2[i] != '\0'; i++) {
        H[s2[i] - 97]--;
    }

    for (int i = 0; i < 25; i++) {
        if (H[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    char *s1 = "maliketh";
    char *s2 = "ethkmali";
    cout << "Are permutations of each other ? " << CheckPermutation(s1, s2);
    return 0;
}