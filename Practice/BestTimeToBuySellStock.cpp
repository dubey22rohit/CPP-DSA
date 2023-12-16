#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
  int l = 0, r = 1;
  int maxProfit = 0;
  while (r < prices.size()) {
    if (prices[l] < prices[r]) {
      int pf = prices[r] - prices[l];
      maxProfit = max(maxProfit, pf);
    } else {
      l = r;
    }
    r++;
  }
  return maxProfit;
}

int main() {
  int n;
  cin >> n;
  vector<int> prices;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    prices.push_back(a);
  }
  int mp = maxProfit(prices);
  cout << mp;
  return 0;
}
