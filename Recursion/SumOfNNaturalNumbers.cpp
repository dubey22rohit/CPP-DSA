#include <iostream>
using namespace std;

int sumOfNNaturalNumbers(int n) {
    if (n <= 0) {
        return 0;
    }
    return sumOfNNaturalNumbers(n - 1) + n;
}

int ISum(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;
    }
    return s;
}

int FormulaSum(int n) { return (n * (n + 1)) / 2; }

int main() {
    int sum = sumOfNNaturalNumbers(5);
    int iSum = ISum(10);
    int formulaSum = FormulaSum(10);
    cout << "sum " << sum << endl;
    cout << "isum " << iSum << endl;
    cout << "Formula Sum " << formulaSum << endl;
    return 0;
}