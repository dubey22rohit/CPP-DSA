#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>,
                 less<pair<double, vector<int>>>>
      pq;

  for (auto p : points) {
    double dist = sqrt(pow(p[0], 2) + pow(p[1], 2));
    pq.push({dist, {p[0], p[1]}});
    if (pq.size() > k) {
      pq.pop();
    }
  }

  vector<vector<int>> ans;
  while (!pq.empty()) {
    ans.push_back(pq.top().second);
    pq.pop();
  }

  return ans;
}

vector<vector<int>> kClosestBetterRuntime(vector<vector<int>>& points, int k) {
  priority_queue<pair<double, int>> pq;
  for (int i = 0; i < points.size(); ++i) {
    double dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
    if (pq.size() < k) {
      pq.push({dist, i});
    } else if (dist < pq.top().first) {
      pq.pop();
      pq.push({dist, i});
    }
  }

  vector<vector<int>> ans;
  while (!pq.empty()) {
    auto [_, index] = pq.top();
    pq.pop();
    ans.push_back(points[index]);
  }
  return ans;
}

// Both the solutions have the same time complexity, the second one has better
// performance, lesser runtime on leetcode.

int main() {
  vector<vector<int>> points{{3, 3}, {5, -1}, {-2, 4}};
  vector<vector<int>> ans = kClosest(points, 2);
  vector<vector<int>> ans2 = kClosestBetterRuntime(points, 2);
  for (const auto& a : ans) {
    cout << a[0] << ", " << a[1] << endl;
  }
  for (const auto& a : ans2) {
    cout << a[0] << ", " << a[1] << endl;
  }
  return 0;
}