#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0
void frequencyCount(vector<int>& arr, int N, int P) {
  // do modify in the given array
  unordered_map<int, int> hm;
  for (auto a : arr) {
    hm[a]++;
  }

  for (int i = 0; i < N; ++i) {
    if (hm.find(i + 1) != hm.end()) {
      arr[i] = hm[i + 1];
    } else {
      arr[i] = 0;
    }
  }
}

int main() {
  vector<int> arr = {2, 3, 2, 3, 5};

  frequencyCount(arr, 5, 5);

  for (auto a : arr) {
    cout << a << " ";
  }

  return 0;
}