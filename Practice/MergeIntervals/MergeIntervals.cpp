#include <iostream>
#include <vector>
using namespace std;

// Merge Intervals (medium)
// TC: O(N * logN)
static vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() < 2) {
        return intervals;
    }
    vector<vector<int>> mergedIntervals;
    sort(intervals.begin(), intervals.end());
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= end) {
            end = max(intervals[i][1], end);
        } else {
            mergedIntervals.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    mergedIntervals.push_back({start, end});
    return mergedIntervals;
}

int main() {
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}, {4, 10}};
    vector<vector<int>> ans = merge(intervals);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i][0] << " " << ans[i][1] << ", ";
    }
    return 0;
}
