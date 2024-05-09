#include <iostream>
using namespace std;

void printKeypadHelper(int num, string options[]) {
    if (num <= 0) {
        cout << "";
        return;
    }
}

void printKeypad(int num) {
    string options[] = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return printKeypadHelper(num, options);
}

int main() { return 0; }