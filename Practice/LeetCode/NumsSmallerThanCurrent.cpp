#include <iostream>
#include <vector>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    int count[102] = {0};
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        count[nums[i]]++;
    }

    for (int i = 1; i < 102; i++) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            ans.push_back(0);
        } else {
            ans.push_back(count[nums[i] - 1]);
        }
    }
    return ans;
}

int main() {
    vector<int> ip;
    ip.push_back(8);
    ip.push_back(1);
    ip.push_back(2);
    ip.push_back(2);
    ip.push_back(3);

    vector<int> ans = smallerNumbersThanCurrent(ip);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans.at(i) << ", ";
    }
    return 0;
}