#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> hm;
    for (int i = 0; i < nums1.size(); i++) {
        if (hm.find(nums1[i]) != hm.end()) {
            continue;
        }
        hm[nums1[i]]++;
    }
    for (int i = 0; i < nums2.size(); i++) {
        if (hm.find(nums2[i]) != hm.end()) {
            hm[nums2[i]]++;
        }
    }

    vector<int> ans;
    unordered_map<int, int>::iterator it = hm.begin();
    while (it != hm.end()) {
        if (it->second > 1) {
            ans.push_back(it->first);
        }
        ++it;
    }
    return ans;
}

int main() {
    vector<int> nums1, nums2;
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        nums1.push_back(a);
    }
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        nums2.push_back(a);
    }

    vector<int> ans = intersection(nums1, nums2);
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}