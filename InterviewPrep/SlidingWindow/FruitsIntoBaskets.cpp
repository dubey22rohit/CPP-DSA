#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Fruits into Baskets(medium)

// Given an array of characters where each character represents a fruit tree,
// you are given two baskets and your goal is to put maximum number of fruits in
// each basket. The only restriction is that each basket can have only one type
// of fruit.
// You can start with any tree,
// but once you have started you can’t skip a tree.You will pick one fruit
// from each tree until you cannot, i.e.,
// you will stop when you have to pick from a third fruit type.
// Write a function to return the maximum number of fruits in both the baskets.

/**
 * @brief Finds the maximum number of fruits that can be put in two baskets,
 * given an array of characters representing fruit trees.
 *
 * The function uses a sliding window approach to iterate through the array.
 * It maintains a hash map to count the occurrence of each fruit type within the
 * window. If the window contains more than two types of fruits, it shrinks the
 * window from the start. The maximum length of the window (i.e., the maximum
 * number of fruits in both baskets) is tracked.
 *
 * @param arr The array of characters representing fruit trees.
 * @return The maximum number of fruits that can be put in both baskets.
 */
static int findLength(const vector<char> &arr) {
  unordered_map<char, int> hm;
  int maxLength = INT_MIN;
  int windowStart = 0;
  for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd) {
    hm[arr[windowEnd]]++;
    while (hm.size() > 2) {
      hm[arr[windowEnd]]--;
      if (hm[arr[windowEnd]] == 0) {
        hm.erase(arr[windowEnd]);
      }
      windowStart++;
    }
    maxLength = max(maxLength, windowEnd - windowStart + 1);
  }
  return maxLength;
}

int main() {
  vector<char> arr{'A', 'B', 'C', 'A', 'C'};
  int maxFruits = findLength(arr);
  cout << maxFruits;
  return 0;
}