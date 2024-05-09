#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
//   priority_queue<double, vector<double>, less<double>> pq;
//   unordered_map<double, vector<int>> hm;
//   for (auto &p : points) {
//     double dist = sqrt(pow(p[0], 2) + pow(p[1], 2));
//     hm[dist] = {p[0], p[1]};
//     pq.push(dist);
//     if (pq.size() > k) {
//       pq.pop();
//     }
//   }

//   vector<vector<int>> ans;
//   while (!pq.empty()) {
//     double dist = pq.top();
//     pq.pop();
//     ans.push_back(hm[dist]);
//   }

//   return ans;
// }

vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
  priority_queue<pair<double, vector<int>>> pq;
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

int main() {
  vector<vector<int>> points = {{0, 1}, {1, 0}};
  vector<vector<int>> ans = kClosest(points, 2);
  for (auto a : ans) {
    cout << a[0] << " " << a[1] << endl;
  }
  return 0;
}
