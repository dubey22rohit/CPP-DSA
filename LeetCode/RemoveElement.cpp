#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == val) {
            k++;
            for (int j = i; j < nums.size() - 1; j++) {
                nums[j] = nums[j + 1];
            }
        }
    }
    for (int i = 0; i < k; i++) {
        cout << nums[i] << ", ";
    }
    return k;
}

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    int k = removeElement(nums, 3);
    return 0;
}