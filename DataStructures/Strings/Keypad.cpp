#include <iostream>
#include <string>
using namespace std;

// TODO:Understand it
int keypadCombinations(int num, string output[], string options[]) {
    if (num == 0) {
        output[0] = "";
        return 1;
    }
    int lastDigit = num % 10;
    int smallNumber = num / 10;
    string smallOutput[500];
    int smallCount = keypadCombinations(smallNumber, smallOutput, options);
    string op = options[lastDigit];
    int k = 0;
    for (int i = 0; i < op.length(); i++) {
        for (int j = 0; j < smallCount; j++) {
            output[k] = smallOutput[j] + op[i];
            k++;
        }
    }
    return k;
}

int main() {
    int num;
    cin >> num;
    string *output = new string[1000];

    string options[] = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};

    int count = keypadCombinations(num, output, options);
    cout << "COUNT: " << count << endl;
    for (int i = 0; i < count; i++) {
        cout << output[i] << endl;
    }
    return 0;
}