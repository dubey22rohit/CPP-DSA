#include <iostream>
using namespace std;

void zeroMatrix(int **matrix, int m, int n) {
    int a = 0, b = 0;
    int flag = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                flag = 1;
                a = i;
                b = j;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    int w = a, x = a, y = b, z = b;
    while (w >= 0 || x < m) {
        if (w >= 0) {
            matrix[w--][b] = 0;
        }
        if (x < m) {
            matrix[x++][b] = 0;
        }
    }
    while (y >= 0 || z < n) {
        if (y >= 0) {
            matrix[a][y--] = 0;
        }
        if (z < n) {
            matrix[a][z++] = 0;
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    int **matrix = new int *[m]();
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n]();
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    zeroMatrix(matrix, m, n);
    cout << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}