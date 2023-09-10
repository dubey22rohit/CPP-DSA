#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size();

    int top = 0, bot = rows - 1;
    while (top <= bot) {
        int row = top + (bot - top) / 2;
        if (target > matrix[row][cols - 1]) {
            top = row + 1;
        } else if (target < matrix[row][0]) {
            bot = row - 1;
        } else {
            break;
        }
    }

    if (top > bot) {
        return false;
    }

    int l = 0, r = cols - 1;
    int row = top + (bot - top) / 2;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (target > matrix[row][mid]) {
            l = mid + 1;
        } else if (target < matrix[row][mid]) {
            r = mid - 1;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i] = vector<int>(n);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            matrix[i][j] = a;
        }
    }

    int target;
    cin >> target;

    bool elementFound = searchMatrix(matrix, target);
    cout << elementFound;

    return 0;
}