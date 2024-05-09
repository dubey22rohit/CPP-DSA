#include <iostream>

template <class T>
class PriorityQueue {
    std::vector<T> pq;

   public:
    PriorityQueue() {}
    int size() { return this->pq.size(); }
    bool isEmpty() { return this->pq.size() == 0; }
    T getMax() {
        if (isEmpty()) {
            return -1;
        }
        return pq[0];
    }
    void insert(T ele) {}
};