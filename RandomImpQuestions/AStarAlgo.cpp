#include <iostream>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    int **graph = new int *[v]();
    for (int i = 0; i < v; i++) {
        graph[i] = new int[v]();
    }

    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    return 0;
}