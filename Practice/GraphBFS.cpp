#include <iostream>
#include <queue>
using namespace std;

void printBFS(bool **graph, int sv, int v, bool *visited) {
    queue<int> pv;
    pv.push(sv);
    visited[sv] = true;
    while (!pv.empty()) {
        int cv = pv.front();
        pv.pop();
        cout << cv << " ";
        for (int i = 0; i < v; i++) {
            if (graph[cv][i] && !visited[i] && i != cv) {
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
            printBFS(graph, i, v, visited);
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