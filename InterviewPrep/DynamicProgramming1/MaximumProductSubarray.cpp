#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/maximum-product-subarray/
int maxProduct(vector<int>& nums) {
  int n = nums.size();
  int maxProd = INT_MIN;
  int prefixProd = 1, suffixProd = 1;
  for (int i = 0; i < n; i++) {
    if (prefixProd == 0) prefixProd = 1;
    if (suffixProd == 0) suffixProd = 1;
    prefixProd *= nums[i];
    suffixProd *= nums[n - i - 1];
    maxProd = max(maxProd, max(prefixProd, suffixProd));
  }
  return maxProd;
}

int main() { return 0; }