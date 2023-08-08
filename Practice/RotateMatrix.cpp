#include <iostream>
using namespace std;

int **rotateMatrix(int **matrix, int n) {
    int **rm = new int *[n];
    for (int i = 0; i < n; i++) {
        rm[i] = new int[n]();
    }
    int i = 0, j = 0;
    while (i < n && j < n) {
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

    int **nm = rotateMatrix(matrix, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << nm[i][j];
        }
    }

    return 0;
}