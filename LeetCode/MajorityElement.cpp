#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (size_t i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }

    unordered_map<int, int>::iterator it = mp.begin();

    int mostOcc = INT32_MIN;
    int majEle;

    while (it != mp.end()) {
        if (it->second > mostOcc) {
            mostOcc = it->second;
            majEle = it->first;
        }
        it++;
    }
    return majEle;
}

int main() {
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    cout << "Majority ele: " << majorityElement(nums);
    return 0;
}