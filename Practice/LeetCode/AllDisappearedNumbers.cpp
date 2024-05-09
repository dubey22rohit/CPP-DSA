#include <iostream>
#include <vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<bool> seen(nums.size() + 1);
    vector<int> ans;
    for (auto c : nums) {
        seen[c] = true;
    }
    for (int i = 1; i <= nums.size(); i++) {
        if (!seen[i]) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = findDisappearedNumbers(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
