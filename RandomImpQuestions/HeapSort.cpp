#include <iostream>
#include <vector>
using namespace std;

void inplaceMinHeapSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        int childIndex = i;
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if (nums[childIndex] < nums[parentIndex]) {
                int temp = nums[childIndex];
                nums[childIndex] = nums[parentIndex];
                nums[parentIndex] = temp;
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    // Remove Elements, up-heapify
    int size = nums.size();
    while (size > 1) {
        int temp = nums[0];
        nums[0] = nums[size - 1];
        nums[size - 1] = temp;
        size--;

        int parentIndex = 0;
        int lChildIndex = (parentIndex * 2) + 1;
        int rChildIndex = (parentIndex * 2) + 2;

        while (lChildIndex < size) {
            int minIndex = parentIndex;
            if (nums[lChildIndex] < nums[minIndex]) {
                minIndex = lChildIndex;
            }
            if (rChildIndex < size && nums[rChildIndex] < nums[minIndex]) {
                minIndex = rChildIndex;
            }
            if (minIndex == parentIndex) {
                break;
            }
            int temp = nums[minIndex];
            nums[minIndex] = nums[parentIndex];
            nums[parentIndex] = temp;

            parentIndex = minIndex;
            lChildIndex = (parentIndex * 2) + 1;
            rChildIndex = (parentIndex * 2) + 2;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0, a; i < n; i++) {
        cin >> a;
        nums.push_back(a);
    }

    inplaceMinHeapSort(nums);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}