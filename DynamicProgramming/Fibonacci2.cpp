#include <iostream>
using namespace std;

int fibonacciR(int n, int *arr) {
    if (n == 0 || n == 1) {
        return n;
    }
    if (arr[n] > 0) {
        return arr[n];
    }
    int op = fibonacciR(n - 1, arr) + fibonacciR(n - 2, arr);
    arr[n] = op;
    return op;
}

int fibonacciI(int n) {
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        arr[i] = 0;
    }
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 2] + arr[i - 1];
    }
    int op = arr[n];
    delete[] arr;
    return op;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    cout << "Fibonacci Recursive: " << fibonacciR(n, arr) << "\n";
    cout << "Fibonacci Iterative: " << fibonacciI(n);

    return 0;
}