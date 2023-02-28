#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> getPathBFSHelper(bool **graph, int v, int sv, int ev,
                             bool *visited) {
    queue<int> pv;
    pv.emplace(sv);
    visited[sv] = true;
    vector<int> ans;
    ans.push_back(sv);

    while (!pv.empty()) {
        int cv = pv.front();
        pv.pop();
        if (cv == ev) {
            ans.push_back(cv);
            break;
        }
        for (int i = 0; i < v; i++) {
            if (graph[cv][i] && !visited[i]) {
                ans.push_back(i);
                pv.emplace(i);
                visited[i] = true;
            }
        }
    }
    return ans;
}

vector<int> getPathBFS(bool **graph, int v, int sv, int ev) {
    bool *visited = new bool[v]();
    return getPathBFSHelper(graph, v, sv, ev, visited);
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

    int sv, ev;
    cout << "Enter starting and ending vertex:\n";
    cin >> sv >> ev;

    vector<int> ans = getPathBFS(graph, v, sv, ev);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    for (int i = 0; i < v; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}