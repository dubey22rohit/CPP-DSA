#include <iostream>
#include <vector>
using namespace std;

vector<int> getPathDFSHelper(bool **graph, int v, int sv, int ev,
                             bool *visited) {
    if (sv == ev) {
        cout << ev << " ";
        return;
    }
    visited[sv] = true;
    for (int i = 0; i < v; i++) {
        if (graph[sv][i] == 1 && !visited[i]) {
            getPathDFSHelper(graph, v, i, ev, visited);
            cout << i << " " << sv;
        }
    }
}

vector<int> getPathDFS(bool **graph, int v, int sv, int ev) {
    bool *visited = new bool[v]();

    vector<int> ans = getPathDFSHelper(graph, v, sv, ev, visited);

    delete[] visited;
    return ans;
}

int main() {
    int v, e;
    cin >> v >> e;

    bool **graph = new bool *[v];
    for (int i = 0; i < v; i++) {
        graph[i] = new bool[v]();
    }

    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    cout << "Enter vertices to get path between: ";
    int sv, ev;
    cin >> sv >> ev;

    vector<int> ans = getPathDFS(graph, v, sv, ev);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    for (int i = 0; i < v; i++) {
        delete[] graph[i];
    }

    delete[] graph;
    return 0;
}