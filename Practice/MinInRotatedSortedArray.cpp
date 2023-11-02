#include <iostream>
using namespace std;

int findMin(vector<int>& nums) {
    int s = 0, e = nums.size() - 1, res = nums[0];
    while (s <= e) {
        if (nums[s] < nums[e]) {
            res = min(res, nums[s]);
            break;
        }
        int mid = s + (e - s) / 2;
        res = min(res, nums[mid]);
        if (nums[mid] >= nums[s]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return res;
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

    int min = findMin(nums);
    cout << "\n" << min;
    return 0;
}