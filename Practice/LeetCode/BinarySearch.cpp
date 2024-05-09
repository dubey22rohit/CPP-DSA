#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (target < nums[mid]) {
            e = mid - 1;
        } else if (target > nums[mid]) {
            s = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    vector<int> nums{10, 20, 30, 40, 50, 60, 70, 80, 90};
    cout << search(nums, 170);
    return 0;
}
