#include <iostream>
using namespace std;

void printDFS(bool **graph, int v, int sv, bool *visited) {
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < v; i++) {
        if (i == sv) {
            continue;
        }
        if (graph[sv][i] && !visited[i]) {
            printDFS(graph, v, i, visited);
        }
    }
}

void DFS(bool **graph, int v) {
    bool *visited = new bool[v]();

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            printDFS(graph, v, i, visited);
        }
    }
    delete[] visited;
}

int main() {
    int v, e;
    cin >> v >> e;

    bool **graph = new bool *[v]();
    for (int i = 0; i < v; i++) {
        graph[i] = new bool[v]();
    }

    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    DFS(graph, v);

    return 0;
}