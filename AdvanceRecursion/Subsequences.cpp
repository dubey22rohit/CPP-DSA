#include <iostream>
using namespace std;

int subsequences(string input, string *output) {
    if (input.empty()) {
        output[0] = "";
        return 1;
    }

    int smallAns = subsequences(input.substr(1), output);

    for (int i = 0; i < smallAns; i++) {
        output[i + smallAns] = input[0] + output[i];
    }

    return 2 * smallAns;
}

int main() {
    string input;
    getline(cin, input);
    string *output = new string[pow(2, input.size())];
    int ans = subsequences(input, output);
    printf("Number of subsequences: %d\n", ans);
    for (int i = 0; i <= ans; i++) {
        cout << output[i] << " ";
    }
    return 0;
}