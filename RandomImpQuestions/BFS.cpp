#include <iostream>
#include <queue>
using namespace std;

void printBFS(bool **graph, int v, int sv, bool *visited) {
    queue<int> pv;
    pv.push(sv);
    visited[sv] = true;
    while (!pv.empty()) {
        int cv = pv.front();
        cout << cv << " ";
        pv.pop();
        for (int i = 0; i < v; i++) {
            if (i == cv) {
                continue;
            }
            if (graph[cv][i] && !visited[i]) {
                pv.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(bool **graph, int v) {
    bool *visited = new bool[v]();

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            printBFS(graph, v, i, visited);
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

    BFS(graph, v);

    return 0;
}