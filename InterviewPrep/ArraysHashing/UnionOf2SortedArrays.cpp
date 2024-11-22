#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Time Compleixty : O( (m+n)log(m+n) )
vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(arr1[i]);
  }
  for (int j = 0; j < m; j++) {
    s.insert(arr2[j]);
  }
  vector<int> u(s.begin(), s.end());
  return u;
}

vector<int> findUnionOp(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0;
  vector<int> u;
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) {
      if (u.empty() || u.back() != arr1[i]) {
        u.push_back(arr1[i]);
      }
      i++;
    } else {
      if (u.empty() || u.back() != arr2[j]) {
        u.push_back(arr2[j]);
      }
      j++;
    }
  }
  while (i < n) {
    if (u.empty() || u.back() != arr1[i]) {
      u.push_back(arr1[i]);
    }
    i++;
  }

  while (j < m) {
    if (u.empty() || u.back() != arr2[j]) {
      u.push_back(arr2[j]);
    }
    j++;
  }
  return u;
}

int main() {
  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[3] = {1, 2, 3};

  vector<int> u = findUnion(arr1, arr2, 5, 3);
  for (auto n : u) {
    cout << n << " ";
  }
  return 0;
}