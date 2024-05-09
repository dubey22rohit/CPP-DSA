#include <iostream>
using namespace std;

bool routeBetweenNodesDFSHelper(bool **graph, int v, int sv, int ev,
                                bool *visited) {
    if (graph[sv][ev]) {
        return true;
    }
    visited[sv] = true;
    for (int i = 0; i < v; i++) {
        if (i == sv) {
            continue;
        }
        if (!visited[i] && graph[sv][i]) {
            return routeBetweenNodesDFSHelper(graph, v, i, ev, visited);
        }
    }
    return false;
}
bool routeBetweenNodesDFS(bool **graph, int v, int sv, int ev) {
    bool *visited = new bool[v]();
    return routeBetweenNodesDFSHelper(graph, v, sv, ev, visited);
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
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    int sv, ev;
    cin >> sv >> ev;

    cout << (routeBetweenNodesDFS(graph, v, sv, ev) ? "has path" : "no path");

    return 0;
}