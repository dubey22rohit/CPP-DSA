#include <iostream>
#include <vector>
using namespace std;

// TC: O(logn)
// SC: O(1)
int indexEqualToValue(vector<int> &nums) {
    int s = 0, e = nums.size() - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (nums[mid] == mid) {
            return mid;
        } else if (nums[mid] < mid) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> ip;
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        ip.push_back(a);
    }

    int ans = indexEqualToValue(ip);
    cout << ans;

    return 0;
}