#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int lastStoneWeight(vector<int> &stones) {
    priority_queue<int, vector<int>> pq;
    for (auto s : stones) {
        pq.push(s);
    }

    while (pq.size() > 1) {
        int ctop = pq.top();
        pq.pop();
        int ntop = pq.top();
        pq.pop();

        if (ctop - ntop > 0) {
            pq.push(ctop - ntop);
        }
    }

    if (pq.empty()) {
        return 0;
    }

    return pq.top();
}
int main() {
    vector<int> stones{1};
    int lsw = lastStoneWeight(stones);
    cout << lsw;
    return 0;
}