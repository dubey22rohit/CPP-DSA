#include <iostream>
using namespace std;

int binarySearchRecursiveHelper(int *input, int ele, int si, int ei) {
    if (si > ei) {
        return -1;
    }
    int mid = si + (ei - si) / 2;
    if (ele < input[mid]) {
        return binarySearchRecursiveHelper(input, ele, si, mid - 1);
    } else if (ele > input[mid]) {
        return binarySearchRecursiveHelper(input, ele, mid + 1, ei);
    } else {
        return mid;
    }
}

int binarySearchRecursive(int *input, int size, int ele) {
    return binarySearchRecursiveHelper(input, ele, 0, size - 1);
}

int main() {
    int n, x;
    cin >> n;

    int *input = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    cin >> x;

    int ans = binarySearchRecursive(input, n, x);
    cout << ans;

    return 0;
}