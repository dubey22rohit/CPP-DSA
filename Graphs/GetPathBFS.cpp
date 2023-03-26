#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Pending: incomplete
vector<int>* getPathBFSHelper(bool** graph, int v, int sv, int ev,
                              bool* visited) {
    queue<int> pv;
    pv.push(sv);
    visited[sv] = true;
    vector<int>* ans = new vector<int>();
    while (!pv.empty()) {
        int cv = pv.front();
        pv.pop();
        if (cv == ev) {
            ans->push_back(ev);
        }
        if (graph[cv][i] && !visited[i]) {
        }
    }
}

vector<int>* getPathBFS(bool** graph, int v, int sv, int ev) {
    bool* visited = new bool[v]();

    vector<int>* ans = getPathBFSHelper(graph, v, sv, ev, visited);

    delete[] visited;
    return ans;
}

int main() {
    // Write your code here
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

    int sv, ev;
    cin >> sv >> ev;

    vector<int>* ans = getPathBFS(graph, v, sv, ev);
    if (ans != NULL) {
        for (int i = 0; i < ans->size(); i++) {
            cout << ans->at(i) << " ";
        }
        delete ans;
    }

    for (int i = 0; i < v; i++) {
        delete[] graph[i];
    }
    delete[] graph;
}