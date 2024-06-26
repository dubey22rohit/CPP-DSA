#include <iostream>
using namespace std;

bool checkNumber(int input[], int size, int x) {
    if (size <= 0) {
        return false;
    }
    if (input[0] == x) {
        return true;
    }
    return checkNumber(input + 1, size - 1, x);
}

int main() {
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int x;
    cin >> x;

    cout << checkNumber(input, n, x);

    return 0;
}