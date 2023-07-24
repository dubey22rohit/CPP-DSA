#include <iostream>
#include <vector>
using namespace std;

int keypadCombinationHelper(int num, vector<string>& output, string options[]) {
    if (num <= 0) {
        output[0] = "";
        return 1;
    }

    int rem = num % 10;
    int div = num / 10;

    vector<string> smallOutput(500);
    int smallAns = keypadCombinationHelper(div, smallOutput, options);
    int k = 0;

    string option = options[rem];

    for (int i = 0; i < option.size(); i++) {
        for (int j = 0; j < smallAns; j++) {
            output[k++] = smallOutput[j] + option[i];
        }
    }
    return k;
}

int keypadCombination(int num, vector<string>& output) {
    string options[] = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return keypadCombinationHelper(num, output, options);
}

int main() {
    int num;
    cin >> num;

    vector<string> output(1000);

    int ans = keypadCombination(num, output);
    printf("the num %d generated %d combinations\n", num, ans);
    for (int i = 0; i < ans; i++) {
        cout << output[i] << " ";
    }

    return 0;
}