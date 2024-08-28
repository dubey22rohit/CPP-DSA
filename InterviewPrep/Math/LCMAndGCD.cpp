#include <iostream>
#include <vector>

using namespace std;

vector<long long> lcmAndGcd(long long A, long long B) {
  long long oa = A, ob = B;
  long long lcm;
  vector<long long> ans;
  while (A > 0 && B > 0) {
    if (A > B) {
      A = A % B;
    } else {
      B = B % A;
    }
    if (A == 0) {
      lcm = (oa * ob) / B;
      ans.push_back(lcm);
      ans.push_back(B);
      break;
    }
    if (B == 0) {
      lcm = (oa * ob) / A;
      ans.push_back(lcm);
      ans.push_back(A);
      break;
    }
  }

  return ans;
}

int main() {
  vector<long long> lcmGcd = lcmAndGcd(14, 8);
  for (auto n : lcmGcd) {
    cout << n << ", ";
  }
  return 0;
}