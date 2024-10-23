#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// NOT OPTIMAL
// TODO: Find optimal solution
vector<int> maxSumComb(vector<int> &A, vector<int> &B, int C) {
  priority_queue<int, vector<int>, less<int>> pq;
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < B.size(); j++) {
      int sum = A[i] + B[j];
      pq.push(sum);
    }
  }

  vector<int> ans;
  while (C >= 1) {
    ans.push_back(pq.top());
    pq.pop();
    C--;
  }
  return ans;
}
int main() {
  vector<int> A{68, 35};
  vector<int> B{68, 35};
  vector<int> ans = maxSumComb(A, B, 1);
  for (auto a : ans) {
    cout << a << ", ";
  }
  return 0;
}