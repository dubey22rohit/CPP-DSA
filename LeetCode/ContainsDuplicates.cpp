#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool containsDuplicates(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (size_t i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
        if (mp[nums[i]] > 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    cout << "Contains Duplicate?: " << containsDuplicates(v);
    return 0;
}