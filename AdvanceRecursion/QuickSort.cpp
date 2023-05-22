#include <iostream>
using namespace std;

// Ninjas code:
int partition(int *input, int si, int ei) {
    int pivot = input[si];
    int count = 0;
    for (int i = si + 1; i <= ei; i++) {
        if (input[i] <= pivot) {
            count++;
        }
    }
    int pivotIndex = si + count;

    int temp = input[si];
    input[si] = input[pivotIndex];
    input[pivotIndex] = temp;

    int i = si, j = ei;
    while (i <= pivotIndex && j >= pivotIndex) {
        while (i <= pivotIndex && input[i] <= pivot) {
            i++;
        }
        while (j >= pivotIndex && input[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(int *input, int si, int ei) {
    if (si >= ei) {
        return;
    }
    int pi = partition(input, si, ei);
    quickSort(input, si, pi - 1);
    quickSort(input, pi + 1, ei);
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, 0, n - 1);
    printf("Array after quick sort:\n");
    for (int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete[] input;

    return 0;
}