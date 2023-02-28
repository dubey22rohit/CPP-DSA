#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/sort-colors/description/

void sortColors(vector<int> &nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                swap(nums[low++], nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid++], nums[high--]);
                break;
        }
    }
}

int main() {
    vector<int> nums{2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}