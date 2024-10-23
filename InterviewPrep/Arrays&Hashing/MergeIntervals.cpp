#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/merge-intervals/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  if (intervals.size() < 2) {
    return intervals;
  }
  vector<vector<int>> mergedIntervals;
  sort(intervals.begin(), intervals.end());
  int start = intervals[0][0];
  int end = intervals[0][1];
  for (int i = 0; i < intervals.size(); i++) {
    if (intervals[i][0] <= end) {
      end = max(end, intervals[i][1]);
    } else {
      mergedIntervals.push_back({start, end});
      start = intervals[i][0];
      end = intervals[i][1];
    }
  }
  mergedIntervals.push_back({start, end});
  return mergedIntervals;
}

int main() { return 0; }