#include <vector>

class MaxHeap {
    std::vector<int> pq;

   public:
    int size() { return pq.size(); }
    bool isEmpty() { return pq.size() == 0; }
    int getMax() { return pq[0]; }
    void insert(int ele) {
        pq.push_back(ele);
        int childIndex = pq.size() - 1;
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parentIndex]) {
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

        int del = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int lChildIndex = (2 * parentIndex) + 1;
        int rChildIndex = (2 * parentIndex) + 2;

        while (lChildIndex < pq.size()) {
            int maxIndex = parentIndex;
            if (pq[lChildIndex] > pq[maxIndex]) {
                maxIndex = lChildIndex;
            }
            if (rChildIndex < pq.size() && pq[rChildIndex] > pq[maxIndex]) {
                maxIndex = rChildIndex;
            }
            if (parentIndex == maxIndex) {
                break;
            }

            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            lChildIndex = (2 * parentIndex) + 1;
            rChildIndex = (2 * parentIndex) + 2;
        }

        return del;
    }
};