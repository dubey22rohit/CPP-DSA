#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int> &nums) {
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }

    unordered_map<int, int>::iterator it = mp.begin();
    while (it != mp.end()) {
        if (it->second >= 2) {
            ans.push_back(it->first);
        }
        ++it;
    }

    return ans;
}

int main() {
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = findDuplicates(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}