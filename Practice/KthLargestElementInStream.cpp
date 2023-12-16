#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
   private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

   public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (auto n : nums) {
            pq.push(n);
        }
        while (pq.size() > this->k) {
            pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > this->k) {
            pq.pop();
        }
        return pq.top();
    }
};

int main() { return 0; }