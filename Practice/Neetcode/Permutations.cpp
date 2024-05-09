#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> &nums, int start, vector<vector<int>> &result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[i], nums[start]);
        dfs(nums, start + 1, result);
        swap(nums[i], nums[start]);
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    dfs(nums, 0, result);
    return result;
}

int main() {
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = permute(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}