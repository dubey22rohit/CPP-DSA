#include <iostream>
using namespace std;

int num_codes(int *arr, int size) {
    if (size == 1) {
        return 1;
    }
    if (size == 0) {
        return 1;
    }

    int output = num_codes(arr, size - 1);
    if (arr[size - 2] * 10 + arr[size - 1] <= 26) {
        output += num_codes(arr, size - 2);
    }
    return output;
}

int num_codes2(int *arr, int size, int *dp) {
    if (size == 1) {
        return 1;
    }
    if (size == 0) {
        return 1;
    }
    if (dp[size] > 0) {
        return dp[size];
    }

    int output = num_codes2(arr, size - 1, dp);
    if (arr[size - 2] * 10 + arr[size - 1] <= 26) {
        output += num_codes2(arr, size - 2, dp);
    }
    dp[size] = output;
    return output;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    int *dp = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 0;
    }

    cout << "Num codes: " << num_codes(arr, n) << endl;
    cout << "Num codes 2: " << num_codes2(arr, n, dp) << endl;

    return 0;
}