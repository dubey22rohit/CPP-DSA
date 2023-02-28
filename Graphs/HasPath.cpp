#include <iostream>
using namespace std;

bool hasPathHelper(int **edges, int n, int sv, int ev, bool *visited) {
    if (edges[sv][ev] == 1) {
        return true;
    }
    visited[sv] = true;
    for (int i = 0; i < n; i++) {
        if (edges[sv][i] && !visited[i]) {
            if (hasPathHelper(edges, n, i, ev, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool hasPath(int **edges, int n, int sv, int ev) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    return hasPathHelper(edges, n, sv, ev, visited);
}

int main() {
    int n, e;

    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int sv, ev;
    cout << "\nEnter starting and ending vertex";
    cin >> sv >> ev;

    bool pathExists = hasPath(edges, n, sv, ev);
    cout << "Path exists?: " << pathExists;

    // Cleanup
    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}