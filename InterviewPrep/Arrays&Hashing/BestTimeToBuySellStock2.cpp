#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
  int l = 0, r = 1, prof = 0;
  while (r < prices.size()) {
    if (prices[l] < prices[r]) {
      int pf = prices[r] - prices[l];
      prof += pf;
    }
    l++;
    r++;
  }
  return prof;
}

int main() {
  vector<int> nums{7, 1, 5, 3, 6, 4};
  cout << maxProfit(nums);
  return 0;
}
