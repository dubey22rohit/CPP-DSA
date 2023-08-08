#include <iostream>
using namespace std;

void printDFS(bool **graph, int sv, int v, bool *visited) {
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < v; i++) {
        if (graph[sv][i] && i != sv && !visited[i]) {
            printDFS(graph, i, v, visited);
        }
    }
}

void DFS(bool **graph, int v) {
    bool *visited = new bool[v]();
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            printDFS(graph, i, v, visited);
        }
    }
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