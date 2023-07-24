#include <iostream>
using namespace std;

void merge(int *input, int si, int ei) {
    int mid = si + (ei - si) / 2;
    int i = si, j = mid + 1, k = si;
    int *temp = new int[mid * 2];
    while (i <= mid && j <= ei) {
        if (input[i] < input[j]) {
            temp[k++] = input[i++];
        } else if (input[i] > input[j]) {
            temp[k++] = input[j++];
        } else {
            temp[k++] = input[i++];
            temp[k++] = input[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = input[i++];
    }

    while (j <= ei) {
        temp[k++] = input[j++];
    }

    for (int z = si; z <= ei; z++) {
        input[z] = temp[z];
    }
}

void mergeSort(int *input, int si, int ei) {
    if (si >= ei) {
        return;
    }

    int mid = si + (ei - si) / 2;
    mergeSort(input, si, mid);
    mergeSort(input, mid + 1, ei);
    merge(input, si, ei);
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    mergeSort(input, 0, n - 1);
    printf("Array after merge sort:\n");
    for (int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete[] input;

    return 0;
}