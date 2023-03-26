#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    int i = 0, j = n - 1, k = n - 1;
    while (i <= j) {
        if (abs(nums[i]) > abs(nums[j])) {
            ans[k--] = nums[i] * nums[i];
            i++;
        } else {
            ans[k--] = nums[j] * nums[j];
            j--;
        }
    }
    return ans;
}

int main() {
    vector<int> ip;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ip.push_back(a);
    }

    vector<int> ans = sortedSquares(ip);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}