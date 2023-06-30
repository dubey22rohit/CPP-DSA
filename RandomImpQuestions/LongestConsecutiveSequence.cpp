#include <iostream>
#include <set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int>& nums) {}

int main() {
    int n;
    cin >> n;
    int a;

    vector<int> nums;

    for (int i = 0; i < n; i++) {
        cin >> a;
        nums.push_back(a);
    }

    int result = longestConsecutive(nums);
    cout << result;

    return 0;
}