#include <iostream>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/subset-sums2234/1

void subsetSumsHelper(vector<int> arr, int n, vector<int>& result, int sum,
                      int idx) {
  if (idx == n) {
    result.push_back(sum);
    return;
  }
  subsetSumsHelper(arr, n, result, sum + arr[idx], idx + 1);
  subsetSumsHelper(arr, n, result, sum, idx + 1);
}
vector<int> subsetSums(vector<int> arr, int n) {
  vector<int> result;
  subsetSumsHelper(arr, n, result, 0, 0);
  return result;
}

int main() {
  vector<int> result = subsetSums(vector<int>{2, 3, 4}, 3);
  for (auto r : result) {
    cout << r << ", ";
  }
  return 0;
}