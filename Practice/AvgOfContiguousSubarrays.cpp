#include <iostream>
#include <vector>
using namespace std;

// Given an array, find the average of all contiguous subarrays of size ‘K’ in
// it. Array: [1, 3, 2, 6, -1, 4, 1, 8, 2], K=5
// Output: [2.2, 2.8, 2.4, 3.6, 2.8]

// Brute Force : TC: O(N * K)
vector<double> findAveragesBF(int K, const vector<int> &arr) {
  vector<double> result(arr.size() - K + 1);
  for (int i = 0; i <= arr.size() - K; i++) {
    double sum = 0;
    for (int j = i; j < i + K; j++) {
      sum += arr[j];
    }
    result[i] = sum / K;
  }
  return result;
}

// Sliding window approach
vector<double> findAverages(int K, const vector<int> &arr) {
  vector<double> result(arr.size() - K + 1);
  int windowStart = 0;
  double windowSum = 0;
  for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd) {
    windowSum += arr[windowEnd];
    if (windowEnd >= K - 1) {
      result[windowStart] = windowSum / K;
      windowSum -= arr[windowStart];
      windowStart++;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  vector<int> arr{1, 3, 2, 6, -1, 4, 1, 8, 2};
  vector<double> resultBF = findAveragesBF(5, arr);
  vector<double> result = findAverages(5, arr);

  for (auto d : resultBF) {
    cout << d << "\n";
  }

  cout << "\noptimized:\n";

  for (auto d : result) {
    cout << d << "\n";
  }
}
