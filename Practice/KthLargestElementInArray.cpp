#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto n : nums) {
        pq.push(n);
    }

    while (pq.size() > k) {
        pq.pop();
    }

    return pq.top();
}

int main() { return 0; }