#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/search-insert-position/description/

int searchInsert(vector<int> &nums, int target) {
    int s = 0, e = nums.size() - 1, mid = 0;
    while (s <= e) {
        mid = s + (e - s) / 2;
        if (target < nums[mid]) {
            e = mid - 1;
        } else if (target > nums[mid]) {
            s = mid + 1;
        } else {
            return mid;
        }
    }
    mid = s + (e - s) / 2;
    return mid;
}

int main() {
    vector<int> nums{1, 3, 5, 6};
    int ans = searchInsert(nums, 5);
    cout << ans;
    return 0;
}