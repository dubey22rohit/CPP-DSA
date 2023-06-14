#include <iostream>
using namespace std;

// TC: O(n^2)
// SC: O(1)
void bubbleSort(vector<int> &nums) {
    bool isSorted = false;
    int counter = 0;  // For minor optimization
    while (!isSorted) {
        isSorted = true;
        for (size_t i = 0; i < nums.size() - 1 - counter; i++) {
            if (nums[i] > nums[i + 1]) {
                int temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
                isSorted = false;
            }
        }
        counter++;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (size_t i = 0, a; i < n; i++) {
        cin >> a;
        nums.push_back(a);
    }

    bubbleSort(nums);
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}