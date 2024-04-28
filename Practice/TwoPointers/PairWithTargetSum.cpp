#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Pair with Target Sum (easy)
static pair<int, int> search(const vector<int> &arr, int targetSum) {
  int left = 0, right = arr.size() - 1;
  while (left < right) {
    int currSum = arr[left] + arr[right];
    if (currSum == targetSum) {
      return make_pair(left, right);
    } else if (currSum > targetSum) {
      right--;
    } else {
      left++;
    }
  }
  return make_pair(-1, -1);
}

int main() {
  pair<int, int> result = search({1, 2, 3, 4, 5, 6}, 6);
  cout << result.first << " " << result.second;
  return 0;
}
