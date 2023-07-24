#include <iostream>
using namespace std;

void removeDuplicates(char input[]) {
    if (input[0] == '\0') {
        return;
    }
    if (input[0] != input[1]) {
        removeDuplicates(input + 1);
    } else {
        int i = 1;
        for (; input[i] != '\0'; i++) {
            input[i - 1] = input[i];
        }
        input[i - 1] = input[i];
        removeDuplicates(input);
    }
}

int main() {
    char input[100];

    cin.get(input, 100);
    removeDuplicates(input);

    cout << "After removing duplicates\n" << input;

    return 0;
}