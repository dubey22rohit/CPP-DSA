#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/maximum-product-subarray/

// brute force: O(n^3)
int maxProductSubarrayBF(vector<int> nums) {
  int n = nums.size();
  int maxProd = INT_MIN;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int prod = 1;
      for (int k = i; k <= j; k++) {
        prod *= nums[k];
      }
      maxProd = max(maxProd, prod);
    }
  }
  return maxProd;
}

// better approach: O(n^2)
int maxProductSubarrayBetter(vector<int> nums) {
  int n = nums.size();
  int maxProd = nums[0];
  for (int i = 0; i < n - 1; i++) {
    int prod = nums[i];
    for (int j = i + 1; j < n; j++) {
      maxProd = max(maxProd, prod);
      prod *= nums[j];
    }
    maxProd = max(maxProd, prod);
  }
  return maxProd;
}

// optimized approach: O(n)
int maxProductSubarrayOptimized(vector<int> nums) {
  int n = nums.size();
  int maxProd = INT_MIN;
  int prefixProd = 1;
  int suffixProd = 1;
  for (int i = 0; i < n; i++) {
    if (prefixProd == 0) {
      prefixProd = 1;
    }
    if (suffixProd == 0) {
      suffixProd = 1;
    }
    prefixProd *= nums[i];
    suffixProd *= nums[n - i - 1];
    maxProd = max(maxProd, max(prefixProd, suffixProd));
  }

  return maxProd;
}

int main() {
  vector<int> nums{2, 3, -2, 4};
  cout << maxProductSubarrayBF(nums) << endl;
  cout << maxProductSubarrayBetter(nums) << endl;
  cout << maxProductSubarrayOptimized(nums) << endl;
  return 0;
}