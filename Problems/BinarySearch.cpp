#include <iostream>
using namespace std;

int rBinarySearch(int *a, int s, int e, int k) {
    if (s > e) {
        return -1;
    }

    int mid = s + (e - s) / 2;

    if (a[mid] == k) {
        return mid;
    } else if (k < a[mid]) {
        return rBinarySearch(a, 0, mid - 1, k);
    } else {
        return rBinarySearch(a, mid + 1, e, k);
    }
}

int iBinarySearch(int *a, int n, int k) {
    int s = 0, e = n - 1;
    int mid;
    while (s < e) {
        mid = s + (e - s) / 2;
        if (a[mid] == k) {
            return mid;
        } else if (k < a[mid]) {
            s = 0;
            e = mid - 1;
        } else {
            s = mid + 1;
            e = n - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    cout << rBinarySearch(arr, 0, sizeof(arr) / sizeof(arr[0]), 6);
    cout << "\n";
    cout << iBinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 6);
    return 0;
}