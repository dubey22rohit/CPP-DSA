#include <vector>

class MinHeap {
    std::vector<int> pq;

   public:
    int getSize() { return pq.size(); }
    int isEmpty() { return pq.empty(); }
    int getMin() { return pq[0]; }
    void insert(int ele) {
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
        int lchildIndex = (2 * parentIndex) + 1;
        int rchildIndex = (2 * parentIndex) + 2;

        while (lchildIndex < pq.size()) {
            int minIndex = parentIndex;
            if (pq[lchildIndex] < pq[minIndex]) {
                minIndex = lchildIndex;
            }
            if (rchildIndex < pq.size() && pq[rchildIndex] < pq[minIndex]) {
                minIndex = rchildIndex;
            }
            if (minIndex == parentIndex) {
                break;
            }

            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;

            parentIndex = minIndex;
            lchildIndex = (2 * parentIndex) + 1;
            rchildIndex = (2 * parentIndex) + 2;
        }

        return ans;
    }
};