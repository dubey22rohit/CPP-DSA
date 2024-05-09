#include <iostream>
#include <vector>
using namespace std;

// TC: O(n), where n is the length of the main array(we traverse through
// majority of the main array)
// SC: O(1)
bool validSubsequence(vector<int> &nums1, vector<int> &nums2) {
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            j++;
        }
        i++;
    }
    return j == nums2.size();
}

int main() {
    vector<int> nums1;
    vector<int> nums2;
    int n, m;
    cin >> n >> m;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        nums1.push_back(a);
    }
    for (int i = 0, a; i < m; i++) {
        cin >> a;
        nums2.push_back(a);
    }
    cout << (validSubsequence(nums1, nums2) ? "valid" : "invalid");
    return 0;
}