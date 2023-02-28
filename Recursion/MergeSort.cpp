#include <iostream>
using namespace std;

void merge(int arr[], int si, int ei) {
    int tmp[100];
    int mid = si + (ei - si) / 2;
    int i = si, j = mid + 1, k = si;
    while (i <= mid && j <= ei) {
        if (arr[i] < arr[j]) {
            tmp[k++] = arr[i++];
        } else if (arr[i] > arr[j]) {
            tmp[k++] = arr[j++];
        } else {
            tmp[k++] = arr[i++];
            tmp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = arr[i++];
    }
    while (j <= ei) {
        tmp[k++] = arr[j++];
    }
    for (int z = si; z <= ei; z++) {
        arr[z] = tmp[z];
    }
}

void mergeSort(int arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, ei);
}

int main() {
    int a[100];
    int n;
    cout << "Enter array size: ";
    cin >> n;
    cout << endl;
    cout << "Enter array : ";
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << endl;
    mergeSort(a, 0, n - 1);
    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}