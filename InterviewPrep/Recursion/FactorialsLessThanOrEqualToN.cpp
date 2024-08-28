#include <iostream>
#include <vector>
using namespace std;

vector<long long> factorialNumbers(long long n) {
  vector<long long> ans;
  long long curr = 1;
  for (int i = 1; i <= n; ++i) {
    curr *= i;
    if (n >= curr) {
      ans.push_back(curr);
    } else {
      break;
    }
  }
  return ans;
}

int main() {
  vector<long long> ans = factorialNumbers(54);
  for (auto a : ans) {
    cout << a << " ";
  }
  return 0;
}