#include <iostream>
using namespace std;

// Pending: some test cases did not pass.
void DFS(bool** graph, int v, int sv, bool* visited) {
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < v; i++) {
        if (graph[sv][i] && !visited[i]) {
            DFS(graph, v, i, visited);
        }
    }
}

void allConnectedComponents(bool** graph, int v) {
    bool* visited = new bool[v]();

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            cout << "\n";
            DFS(graph, v, i, visited);
        }
    }
    delete[] visited;
}

int main() {
    int v, e;
    cin >> v >> e;

    bool** graph = new bool*[v];
    for (size_t i = 0; i < v; i++) {
        graph[i] = new bool[v]();
    }

    for (size_t i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    allConnectedComponents(graph, v);

    for (int i = 0; i < v; i++) {
        delete[] graph[i];
    }

    delete[] graph;

    return 0;
}