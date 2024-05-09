#include <iostream>
using namespace std;

void printAllPossibleCodes(string input) {
    if (input.empty()) {
        return;
    }
    cout << input;
    for (int i = 0; i < input.size(); i++) {
        printAllPossibleCodes(input.substr(1));
    }
    for (int i = 0; i < input.size(); i++) {
        if (input.size() >= 2) {
            printAllPossibleCodes(input.substr(2));
        }
    }
    cout << endl;
}

int main() {
    string s;
    getline(cin, s);

    printAllPossibleCodes(s);

    return 0;
}