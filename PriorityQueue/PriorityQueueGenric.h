#include <vector>

template <class T>
class PriorityQueue {
    std::vector<T> pq;

   public:
    PriorityQueue() {}
    int size() { return this->pq.size(); }
    bool isEmpty() { return this->pq.size() == 0; }
    T getMin() {
        if (isEmpty()) {
            return -1;
        }
        return pq[0];
    }
    void insert(T ele) {
        pq.push_back(ele);
        int childIndex = pq.size() - 1;
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }
    T remove() {
        if (isEmpty()) {
            return -1;
        }

        T ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int lChildIndex = (2 * parentIndex) + 1;
        int rChildIndex = (2 * parentIndex) + 2;

        while (lChildIndex < pq.size()) {
            int minIndex = parentIndex;
            if (pq[lChildIndex] < pq[minIndex]) {
                minIndex = lChildIndex;
            }
            if (rChildIndex < pq.size() && pq[rChildIndex] < pq[minIndex]) {
                minIndex = rChildIndex;
            }
            if (minIndex == parentIndex) {
                break;
            }
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;

            parentIndex = minIndex;
            lChildIndex = (2 * parentIndex) + 1;
            rChildIndex = (2 * parentIndex) + 2;
        }
        return ans;
    }
};