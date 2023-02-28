#include <iostream>
using namespace std;

int minStepsToOne(int n) {
    if (n <= 1) {
        return 0;
    }

    int x = minStepsToOne(n - 1), y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0) {
        y = minStepsToOne(n / 2);
    }
    if (n % 3 == 0) {
        z = minStepsToOne(n / 3);
    }

    int ans = min(x, min(y, z)) + 1;
    return ans;
}

int minStepsToOneMemo(int n, int *arr) {
    if (n <= 1) {
        return 0;
    }

    if (arr[n] > 0) {
        printf("\nUsing an already stored solution for %d: %d\n", n, arr[n]);
        return arr[n];
    }

    int x = minStepsToOneMemo(n - 1, arr), y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0) {
        y = minStepsToOneMemo(n / 2, arr);
    }
    if (n % 3 == 0) {
        z = minStepsToOneMemo(n / 3, arr);
    }

    int ans = min(x, min(y, z)) + 1;
    arr[n] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << minStepsToOne(n) << endl;

    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
    }

    cout << minStepsToOneMemo(n, arr) << endl;
    return 0;
}