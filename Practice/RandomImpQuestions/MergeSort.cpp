#include <iostream>
using namespace std;

void merge(int a[], int si, int ei) {
    int mid = si + (ei - si) / 2;
    int tmp[100];
    int i = si, j = mid + 1, k = si;
    while (i <= mid && j <= ei) {
        if (a[i] < a[j]) {
            tmp[k++] = a[i++];
        } else if (a[i] > a[j]) {
            tmp[k++] = a[j++];
        } else {
            tmp[k++] = a[i++];
            tmp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        tmp[k++] = a[i++];
    }

    while (j <= ei) {
        tmp[k++] = a[j++];
    }
    for (int i = si; i <= ei; i++) {
        a[i] = tmp[i];
    }
}

void mergeSort(int a[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    mergeSort(a, si, mid);
    mergeSort(a, mid + 1, ei);
    merge(a, si, ei);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);
    printf("Array after merge sort:\n");
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}