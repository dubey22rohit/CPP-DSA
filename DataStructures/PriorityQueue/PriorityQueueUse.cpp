#include <iostream>

// #include "PriorityQueue.h"
#include "PriorityQueueGenric.h"
using namespace std;

int main() {
    PriorityQueue<int> pq;
    pq.insert(100);
    pq.insert(10);
    pq.insert(15);
    pq.insert(4);
    pq.insert(17);
    pq.insert(21);
    pq.insert(67);

    cout << pq.size() << endl;
    cout << pq.getMin() << endl;

    while (!pq.isEmpty()) {
        cout << pq.remove() << " ";
    }

    return 0;
}