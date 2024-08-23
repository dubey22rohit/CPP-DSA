#include <iostream>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
  // Max priority queue, largest element is removed first.
  priority_queue<int, vector<int>, less<int>> pq{stones.begin(), stones.end()};

  while (pq.size() > 1) {
    int e1 = pq.top();
    pq.pop();
    int e2 = pq.top();
    pq.pop();
    e1 -= e2;
    if (e1) {
      pq.push(e1);
    }
  }

  return pq.empty() ? 0 : pq.top();
}

int main() {
  vector<int> stones{2, 7, 4, 1, 8, 1};
  int stoneWeight = lastStoneWeight(stones);
  cout << stoneWeight;
  return 0;
}