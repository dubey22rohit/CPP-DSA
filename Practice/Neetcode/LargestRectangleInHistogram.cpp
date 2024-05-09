#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//! Revise this
int largestRectangleArea(vector<int> &heights) {
  stack<pair<int, int>> stk;
  int maxArea = INT_MIN;
  for (int i = 0; i < heights.size(); i++) {
    int start = i;
    while (!stk.empty() && stk.top().second > heights[i]) {
      int index = stk.top().first;
      int width = i - index;
      int height = stk.top().second;
      stk.pop();

      maxArea = max(maxArea, width * height);
      start = index;
    }
    stk.push({start, heights[i]});
  }

  while (!stk.empty()) {
    int width = heights.size() - stk.top().first;
    int height = stk.top().second;
    stk.pop();

    maxArea = max(maxArea, width * height);
  }

  return maxArea;
}

int main() { return 0; }
