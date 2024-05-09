#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }

    vector<vector<int>> bucket(n + 1);
    for (auto it = mp.begin(); it != mp.end(); it++) {
        bucket[it->second].push_back(it->first);
    }

    vector<int> result;
    for (int i = n; i >= 0; i--) {
        if (result.size() >= k) {
            break;
        }
        if (!bucket[i].empty()) {
            // result.insert(result.end(), buckets[i].begin(),
            // buckets[i].end()); Can do this as well.
            for (int j = 0; j < bucket[i].size(); j++) {
                result.push_back(bucket[i][j]);
            }
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        nums.push_back(a);
    }

    int k;
    cin >> k;
    vector<int> result = topKFrequent(nums, k);
    for (int i = 0; i < k; i++) {
        cout << result[i] << " ";
    }

    return 0;
}