#include <iostream>
#include <vector>
using namespace std;

bool check(int cows, vector<int> &stalls, int dist) {
    int count = 1;
    int last_pos = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last_pos >= dist) {
            last_pos = stalls[i];
            count++;
        }
        if (cows == count) {
            return true;
        }
    }
    return false;
}

int agressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int end = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (check(k, stalls, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        int ele;
        for (size_t i = 0; i < n; i++) {
            cin >> ele;
            v.push_back(ele);
        }
        cout << "Max distance bw cows: " << agressiveCows(v, k);
    }
    return 0;
}