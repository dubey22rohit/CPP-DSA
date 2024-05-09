#include <iostream>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0, k = 0;
    vector<int> ans;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            i++;
            k = j + 1;
            while (k < nums2.size()) {
                if (nums2[k] > nums2[j]) {
                    ans.push_back(nums2[k]);
                    break;
                }
                k++;
            }
            if (k == nums2.size()) {
                ans.push_back(-1);
            }
            j = 0;
            continue;
        }
        j++;
    }
    return ans;
}

int main() {
    vector<int> nums1{4, 1, 2};
    vector<int> nums2{1, 3, 4, 2};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}