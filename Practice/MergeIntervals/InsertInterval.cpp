#include<iostream>
#include<vector>
using namespace std;

// Insert Interval (medium)
// The given interval list is sorted, otherwise we could have just insterted the new interval
// in the list and called the merge function from MergeIntervals.cpp
vector<vector<int>> insert(const vector<vector<int>> &intervals, vector<int> newInterval){
    if(intervals.empty()){
        return {newInterval};
    }
    vector<vector<int>> mergedIntervals;
    
    int i = 0;
    int start = newInterval[0];
    int end = newInterval[1];
    while(i < intervals.size() && intervals[i][1] < newInterval[0]){
        mergedIntervals.push_back(intervals[i++]);
    }

    while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
        start = min(start, intervals[i][0]);
        end = max(end, intervals[i][1]);
        i++;
    }

    mergedIntervals.push_back({start, end});

    while(i < intervals.size()){
        mergedIntervals.push_back(intervals[i++]);
    }

    return mergedIntervals;
}

int main(){
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<vector<int>> ans = insert(intervals, {4, 8});

    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i][0] << " " << ans[i][1] << ", ";
    }

    return 0;
}