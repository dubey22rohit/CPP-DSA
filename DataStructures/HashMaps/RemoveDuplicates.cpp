#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> RemoveDuplicates(vector<int> &nums) {
    unordered_map<int, bool> mp;
    vector<int> op;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.count(nums[i]) > 0) {
            continue;
        }
        mp[nums[i]] = true;
        op.push_back(nums[i]);
    }
    return op;
}

int main() {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(1);
    arr.push_back(2);

    vector<int> ans = RemoveDuplicates(arr);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}