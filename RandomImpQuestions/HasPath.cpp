#include <iostream>
using namespace std;

bool hasPathHelper(bool **graph, int v, int sv, int ev, bool *visited) {
    if (graph[sv][ev]) {
        return true;
    }
    visited[sv] = true;
    for (int i = 0; i < v; i++) {
        if (i == sv) {
            continue;
        }
        if (graph[sv][i] && !visited[i]) {
            if (hasPathHelper(graph, v, i, ev, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool hasPath(bool **graph, int v, int sv, int ev) {
    bool *visited = new bool[v]();

    bool path = hasPathHelper(graph, v, sv, ev, visited);

    delete[] visited;
    return path;
}

int main() {
    // 6 8
    // 0 5
    // 0 1
    // 0 4
    // 1 4
    // 1 3
    // 2 1
    // 3 2
    // 3 4

    int v, e;
    cin >> v >> e;

    bool **graph = new bool *[v]();
    for (int i = 0; i < v; i++) {
        graph[i] = new bool[v]();
    }

    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        graph[a][b] = true;
    }

    int sv, ev;
    cin >> sv >> ev;
    cout << (hasPath(graph, v, sv, ev) ? "has path" : "no path");

    return 0;
}