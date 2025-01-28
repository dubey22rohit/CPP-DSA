#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// https://leetcode.com/problems/course-schedule/

unordered_map<int, vector<int>> preMap;
unordered_set<int> visited;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  for (int i = 0; i < numCourses; i++) {
    preMap[i] = {};
  }

  for (const auto& preq : prerequisites) {
    preMap[preq[0]].push_back(preq[1]);
  }

  for (int c = 0; c < numCourses; c++) {
    if (!dfs(c)) {
      return false;
    }
  }

  return true;
}

bool dfs(int crs) {
  if (visited.count(crs)) {
    return false;
  }
  if (preMap[crs].empty()) {
    return true;
  }

  visited.insert(crs);
  for (int c : preMap[crs]) {
    if (!dfs(c)) {
      return false;
    }
  }
  visited.erase(crs);
  preMap[crs].clear();
  return true;
}

int main() { return 0; }