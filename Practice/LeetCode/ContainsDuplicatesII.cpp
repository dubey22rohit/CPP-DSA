#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * * Fairly optimized
 * * Runtime 174ms (beats 89%)
 * * Memory 77.3mb (beats 48%)
 */

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> hm;
    for (int i = 0; i < nums.size(); i++) {
        if (hm.find(nums[i]) != hm.end()) {
            int li = hm[nums[i]];
            if (abs(li - i) <= k) {
                return true;
            }
        }
        hm[nums[i]] = i;
    }
    return false;
}

int main() {
    int n, a;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> a;
        nums.push_back(a);
    }
    int k;
    cin >> k;
    bool ans = containsNearbyDuplicate(nums, k);
    cout << ans;
    return 0;
}