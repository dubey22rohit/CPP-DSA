#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void reverseArray(int *arr, int n) {
  int s = 0, e = n - 1;
  while (s < e) {
    swap(arr[s], arr[e]);
    s++;
    e--;
  }
}

void rotateMatrix(int **matrix, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      // Transpose
      swap(matrix[i][j], matrix[j][i]);
    }
    // reverse
    reverseArray(matrix[i], n);
  }
}

int main() {
  int n;
  cin >> n;
  int **matrix = new int *[n]();
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[n]();
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  rotateMatrix(matrix, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
