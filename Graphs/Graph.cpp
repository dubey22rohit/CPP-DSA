#include <iostream>
#include <queue>
using namespace std;

// DFS
void printDFS(int **edges, int v, int startV, bool *visited) {
    cout << startV << endl;
    visited[startV] = true;
    for (int i = 0; i < v; i++) {
        if (i == startV) {
            continue;
        }
        if (edges[startV][i] == 1 && !visited[i]) {
            printDFS(edges, v, i, visited);
        }
    }
}

// BFS
void printBFS(int **edges, int v, int sv, bool *visited) {
    queue<int> pn;
    pn.push(sv);
    visited[sv] = true;
    while (!pn.empty()) {
        int curr = pn.front();
        pn.pop();
        cout << curr << endl;
        for (size_t i = 0; i < v; i++) {
            if (curr == i) {
                continue;
            }
            if (egdes[curr][i] == 1 && !visited[i]) {
                pn.push(i);
                visited[i] = true;
            }
        }
    }
}

// For disconnected graphs:
void BFS(int **edges, int v) {
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            printBFS(edges, v, i, visited);
        }
    }
    delete[] visited;
}

void DFS(int **edges, int v) {
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            printDFS(edges, v, i, visited);
        }
    }
    delete[] visited;
}

int main() {
    int v;
    int e;
    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "\n";

    cout << "Enter number of edges: ";
    cin >> e;

    int **edges = new int *[v];
    for (int i = 0; i < v; i++) {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++) {
            edges[i][j] = 0;
        }
    }
    cout
        << "\nEnter first and second vertex, between which there is an edge:\n";

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // bool *visited = new bool[v];
    // for (int i = 0; i < v; i++) {
    //     visited[i] = false;
    // }

    cout << "DFS:\n";
    // printDFS(edges, v, 0, visited);
    DFS(edges, v);

    cout << "\nBFS:\n";
    // printBFS(edges, v, 0);
    BFS(edges, v);

    for (int i = 0; i < v; i++) {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}