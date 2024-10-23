#include <iostream>
#include <vector>
using namespace std;

// https://www.naukri.com/code360/problems/subset-sum_630213

bool dfs(int n, int k, vector<int> &a, int currSum, int index) {
  if (index >= n) {
    return false;
  }

  cout << "\n\n currSum: " << currSum << "\n";
  if (currSum == k) {
    return true;
  }

  dfs(n, k, a, currSum + a[index], index + 1);
  dfs(n, k, a, currSum, index + 1);
}

bool isSubsetPresent(int n, int k, vector<int> &a) {
  return dfs(n, k, a, 0, 0);
}

int main() {
  vector<int> a{4, 2, 5, 6, 7};
  int sum = 14;
  cout << (isSubsetPresent(5, 14, a) ? "Yes" : "No");
  return 0;
}