#include <iostream>
#include <queue>
using namespace std;

void BFSHelper(bool **graph, int v, int sv, bool *visited) {
    queue<int> pv;
    pv.emplace(sv);
    while (!pv.empty()) {
        int cv = pv.front();
        pv.pop();
        cout << cv << ": ";
        for (int i = 0; i < v; i++) {
            if (graph[cv][i] && !visited[i]) {
                pv.emplace(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(bool **graph, int v) {
    bool *visited = new bool[v]();

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            BFSHelper(graph, v, sv, visited);
        }
    }
    deleted[] visited;
}

void DFSHelper(bool **graph, int v, int sv, bool *visited) {
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < v; i++) {
        if (graph[sv][i] && !visited[i]) {
            DFSHelper(graph, v, i, visited);
        }
    }
}

void DFS(bool **graph, int v) {
    bool *visited = new bool[v]();
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            DFSHelper(graph, v, i, visited);
        }
    }
    delete[] visited;
}

int main() {
    int v, e;
    cin >> v >> e;

    bool **graph = new bool[v];
    for (int i = 0; i < v; i++) {
        graph[i] = new bool[v]();
    }

    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    cout << "DFS:\n";
    DFS(graph, v);

    cout << "BFS:\n";
    BFS(graph, v);

    return 0;
}
