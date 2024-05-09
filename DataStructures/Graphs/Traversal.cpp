#include <iostream>
#include <queue>
using namespace std;

void BFSHelper(bool** graph, int v, int sv, bool* visited) {
    queue<int> pv;
    pv.emplace(sv);
    visited[sv] = true;
    while (!pv.empty()) {
        int cv = pv.front();
        cout << cv << " ";
        pv.pop();

        for (int i = 0; i < v; i++) {
            if (graph[cv][i] == 1 && !visited[i]) {
                pv.emplace(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(bool** graph, int v) {
    bool* visited = new bool[v]();

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            BFSHelper(graph, v, i, visited);
        }
    }

    delete[] visited;
}

void DFSHelper(bool** graph, int v, int sv, bool* visited) {
    cout << sv << " ";
    visited[sv] = true;

    for (int i = 0; i < v; i++) {
        if (graph[sv][i] == 1 && !visited[i]) {
            DFSHelper(graph, v, i, visited);
        }
    }
}

void DFS(bool** graph, int v) {
    bool* visited = new bool[v]();

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

    bool** graph = new bool*[v];
    for (int i = 0; i < v; i++) {
        graph[i] = new bool[v]();
    }

    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    cout << "DFS:\n";
    DFS(graph, v);

    cout << "\nBFS:\n";
    BFS(graph, v);
    return 0;
}