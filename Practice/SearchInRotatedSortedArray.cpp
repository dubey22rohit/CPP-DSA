#include <iostream>
using namespace std;

int search(vector<int> &nums, int target) {
    int s = 0, e = nums.size() - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
    }
}

int main() {
    int n;
    cin >> n;
    // 00008030-000A18A60AE1802E
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