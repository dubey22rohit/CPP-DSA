#include <iostream>
using namespace std;
int binarySearchRecursiveHelper(int *input, int s, int e, int k) {
    if (s >= e) {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (input[mid] > k) {
        return binarySearchRecursiveHelper(input, s, mid - 1, k);
    } else if (input[mid] < k) {
        return binarySearchRecursiveHelper(input, mid + 1, e, k);
    } else {
        return mid;
    }
    return -1;
}
int binarySearchRecursive(int *input, int n, int x) {
    return binarySearchRecursiveHelper(input, 0, n - 1, x);
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;
    cin >> x;
    int ans = binarySearchRecursive(input, n, x);
    printf("%d found at index: %d", x, ans);

    return 0;
}