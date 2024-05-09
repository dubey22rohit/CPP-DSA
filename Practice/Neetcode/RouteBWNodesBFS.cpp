#include <iostream>
#include <queue>
using namespace std;

//! incomplete
bool hasPathBFS(bool** graph, int v, int sv, int ev) {
    queue<int> pv;
    bool* visited = new bool[v]();
    visited[sv] = true;
    pv.push(sv);
    while (!pv.empty()) {
        int cv = pv.front();
        pv.pop();

        for (int i = 0; i < v; i++) {
            if (!visited[i] && graph[i][ev]) {
                return true;
            }
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    bool** graph = new bool*[v]();
    for (int i = 0; i < v; i++) {
        graph[i] = new bool[v]();
    }

    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    int sv, ev;
    cin >> sv >> ev;

    cout << (hasPathBFS(graph, v, sv, ev) ? "has path" : "no path");

    return 0;
}