#include <iostream>
using namespace std;

int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target <= nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (nums[mid] <= target && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;

    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        nums.push_back(a);
    }

    int target;
    cin >> target;

    int ele = search(nums, target);
    cout << "\n" << ele;
    return 0;
}