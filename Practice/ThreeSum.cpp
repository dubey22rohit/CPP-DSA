#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int threeSum = nums[i] + nums[l] + nums[r];
            if (threeSum == 0) {
                ans.push_back({nums[i], nums[l], nums[r]});
                l++;
                while (nums[l] == nums[l - 1] && l < r) {
                    l++;
                }
            } else if (nums[i] + nums[l] + nums[r] > 0) {
                r--;
            } else {
                l++;
            }
        }
    }
    return ans;
}

int main() {
    int n, target;
    cin >> n;
    vector<int> numbers;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        numbers.push_back(a);
    }

    vector<vector<int>> ans = threeSum(numbers);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}