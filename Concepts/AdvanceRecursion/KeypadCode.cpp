#include <iostream>
using namespace std;

int keypadHelper(int num, string output[], string options[]) {
    if (num <= 0) {
        output[0] = "";
        return 1;
    }
    int rem = num % 10;
    int div = num / 10;
    string smallOutput[500];
    int smallAns = keypadHelper(div, smallOutput, options);
    int k = 0;

    string op = options[rem];

    for (int i = 0; i < op.length(); i++) {
        for (int j = 0; j < smallAns; j++) {
            output[k++] = smallOutput[j] + op[i];
        }
    }
    return k;
}

int keypad(int num, string output[]) {
    string options[] = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return keypadHelper(num, output, options);
}

int main() {
    int num;
    cin >> num;
    string *output = new string[1000];
    int ans = keypad(num, output);
    printf("Number of keypad combinations: %d\n", ans);
    for (int i = 0; i <= ans; i++) {
        cout << output[i] << " ";
    }
    return 0;
}