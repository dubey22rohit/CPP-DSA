#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSumVect(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        if (map.find(target - nums[i]) != map.end()) {
            return {i, map[target - nums[i]]};
        }
        map[nums[i]] = i;
    }
    return {};
}

int *twoSum(int *nums, int numsSize, int target) {
    int *H;
    H = new int[100];

    int ans[2];
    for (int i = 0; i < numsSize; i++) {
        if (H[target - nums[i]] != 0) {
            ans[0] = i;
            ans[1] = nums[target - nums[i]];
            break;
        }
        H[nums[i]]++;
    }
    return ans;
}

int main() {
    // int arr[10] = {0, 1, 2, 4, 3, 5, 6, 7, 8, 9};

    // int *ans;

    // ans = twoSum(arr, 10, 10);

    // int i = ans[0];
    // int j = ans[1];

    // cout << i << " " << j << endl;
    // cout << arr[i] << " " << arr[j] << endl;

    vector<int> arr2;
    for (int i = 0; i < 10; i++) {
        arr2.push_back(i);
    }
    vector<int> ans2;
    ans2 = twoSumVect(arr2, 10);

    int k = ans2[0];
    int l = ans2[1];

    cout << k << " " << l << endl;
    cout << arr2[k] << " " << arr2[l] << endl;

    return 0;
}