#include <iostream>
#include <queue>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited) {
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++) {
        if (i == sv) {
            continue;
        }
        if (edges[sv][i] == 1 && !visited[i]) {
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv, bool *visited) {
    queue<int> pv;
    pv.emplace(sv);
    visited[sv] = true;
    while (!pv.empty()) {
        int cv = pv.front();
        cout << cv << " ";
        pv.pop();
        for (int i = 0; i < n; i++) {
            if (i == cv) {
                continue;
            }
            if (edges[cv][i] && !visited[i]) {
                pv.emplace(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int **edges, int n) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // For un-connected graph, we need to scan all the vertices of the visited
    // array to make sure that none of it is false.
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printDFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

void BFS(int **edges, int n) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // For un-connected graph, we need to scan all the vertices of the visited
    // array to make sure that none of it is false.
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printBFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

int main() {
    int n, e;
    cin >> n >> e;

    // Creating a new adjacency matrix to store graph
    // n is the number of vertices, e is the number oof edges
    int **edges = new int *[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            // Initializing the adjacency matrix with 0
            edges[i][j] = 0;
        }
    }

    // Taking vertices bw which there is an edge and assigning 1 to that
    // location
    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << "DFS:\n";
    DFS(edges, n);

    cout << "\nBFS:\n";
    BFS(edges, n);

    // Delete all memory
    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}