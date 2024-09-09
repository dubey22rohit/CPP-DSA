#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int arr[5] = {5, 1, 2, 7, 4};
  bubbleSort(arr, 5);
  for (auto a : arr) {
    cout << a << " ";
  }
  return 0;
}