#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// All values in the input array is between 1 and n

// TC: O(n)
// SC: O(1)
int firstDuplicateValueBetter(vector<int> &nums) {
    for (int val : nums) {
        if (nums[abs(val) - 1] < 0) {
            return abs(val);
        }
        nums[abs(val) - 1] *= -1;
    }
    return -1;
}

// TC: O(n)
// SC: O(n)
int firstDuplicateValue(vector<int> &nums) {
    unordered_map<int, int> hm;
    for (int i = 0; i < nums.size(); i++) {
        if (hm.find(nums[i]) != hm.end() && hm[nums[i]] == 1) {
            return nums[i];
        }
        hm[nums[i]]++;
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

    // int ans = firstDuplicateValue(ip);
    int ans = firstDuplicateValueBetter(ip);
    cout << ans;
    return 0;
}