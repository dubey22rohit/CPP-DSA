#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return fibonacci(n - 2) + fibonacci(n - 1);
}

int fib2(int n, int *arr) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (arr[n] > 0) {
        return arr[n];
    }
    int output = fib2(n - 1, arr) + fib2(n - 2, arr);
    arr[n] = output;
    return output;
}

int fibi(int n) {
    int *arr = new int[n + 1];
    arr[0] = 1;
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
    // int ans = fibonacci(n);
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        arr[i] = 0;
    }
    int ans = fib2(n, arr);
    cout << ans << endl;

    int ans2 = fibi(n);
    cout << "fibi ans:" << ans2 << endl;
    return 0;
}
