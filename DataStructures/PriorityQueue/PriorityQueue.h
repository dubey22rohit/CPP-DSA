#include <vector>
//! MIN Priority Queue
//! We'll use an array to create a Heap(Complete binary tree)

class PriorityQueue {
    std::vector<int> pq;

   public:
    PriorityQueue() {}

    bool isEmpty() { return pq.size() == 0; }
    int getSize() { return pq.size(); }
    int getMin() {
        if (isEmpty()) {
            return -1;
        }
        return pq[0];
    }
    void insert(int ele) {
        // Satisfying the heap order property(min heap in this case) and
        // CBT(Complete binary tree) property (All levels full except the last
        // from L to R)
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
    int remove() {
        if (isEmpty()) {
            return -1;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int lChildIndex = (2 * parentIndex) + 1;
        int rChildIndex = (2 * parentIndex) + 2;

        while (lChildIndex < pq.size()) {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[lChildIndex]) {
                minIndex = lChildIndex;
            }
            if (rChildIndex < pq.size() && pq[rChildIndex] < pq[minIndex]) {
                minIndex = rChildIndex;
            }
            if (minIndex == parentIndex) {
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            lChildIndex = (2 * parentIndex) + 1;
            rChildIndex = (2 * parentIndex) + 2;
        }
        return ans;
    };
};
