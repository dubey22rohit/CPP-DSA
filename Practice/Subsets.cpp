#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> &nums, int start, vector<int> &curr,
         vector<vector<int>> &result) {
    result.push_back(curr);
    for (int i = start; i < nums.size(); i++) {
        curr.push_back(nums[i]);
        dfs(nums, i + 1, curr, result);
        curr.pop_back();
    }
}

// TC: O(n.2^n)
vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> curr;
    vector<vector<int>> result;
    dfs(nums, 0, curr, result);
    return result;
}

int main() {
    // int n;
    // cin >> n;
    vector<int> nums{1, 2, 3};
    // for (int i = 0, a; i < n; i++) {
    //     cin >> a;
    //     nums.push_back(a);
    // }

    vector<vector<int>> ss = subsets(nums);
    for (int i = 0; i < ss.size(); i++) {
        for (int j = 0; j < ss[i].size(); j++) {
            cout << ss[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}