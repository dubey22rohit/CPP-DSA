#include <iostream>
using namespace std;

// In-place heap sort
void inplaceHeapSort(int input[], int n) {
    for (int i = 1; i < n; i++) {
        int childIndex = i;
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if (input[childIndex] < input[parentIndex]) {
                int temp = input[childIndex];
                input[childIndex] = input[parentIndex];
                input[parentIndex] = temp;
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    // Remove elements, up-heapify
    int size = n;
    while (size > 1) {
        int temp = input[0];
        input[0] = input[size - 1];
        input[size - 1] = temp;
        size--;

        int parentIndex = 0;
        int lChildIndex = (2 * parentIndex) + 1;
        int rChildIndex = (2 * parentIndex) + 2;
        while (lChildIndex < size) {
            int minIndex = parentIndex;
            if (input[lChildIndex] < input[parentIndex]) {
                minIndex = lChildIndex;
            }
            if (input[rChildIndex] < input[parentIndex] && rChildIndex < size) {
                minIndex = rChildIndex;
            }
            if (minIndex == parentIndex) {
                break;
            }
            int temp = input[minIndex];
            input[minIndex] = input[parentIndex];
            input[parentIndex] = temp;

            parentIndex = minIndex;
            lChildIndex = (2 * parentIndex) + 1;
            rChildIndex = (2 * parentIndex) + 2;
        }
    }
}
int main() {
    int input[] = {5, 1, 2, 0, 8};
    int n = sizeof(input) / sizeof(input[0]);
    inplaceHeapSort(input, n);
    for (size_t i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    return 0;
}