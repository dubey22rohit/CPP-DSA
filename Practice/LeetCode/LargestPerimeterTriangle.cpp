#include <iostream>
#include <vector>
using namespace std;

int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 3; i >= 0; --i) {
        if (nums[i] + nums[i + 1] > nums[i + 2]) {
            return nums[i] + nums[i + 1] + nums[i + 2];
        }
    }
    return 0;
}

int main() {
    vector<int> arr;

    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(2);

    cout << largestPerimeter(arr);
    return 0;
}