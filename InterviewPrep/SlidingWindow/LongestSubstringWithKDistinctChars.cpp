#include <iostream>
#include <unordered_map>
using namespace std;

// Longest Substring with K Distinct Characters (medium)
// Given a string, find the length of the longest substring in it with no more
// than K distinct characters.

/**
 * @brief Finds the length of the longest substring in a given string that has
 * no more than K distinct characters.
 *
 * @param str The input string.
 * @param k The maximum number of distinct characters allowed in the substring.
 * @return The length of the longest substring with K distinct characters.
 */
int findLength(const string &str, int k) {
  // Create a hash map to store the count of each character in the substring.
  unordered_map<char, int> hm;

  // Initialize variables to track the maximum length and the start of the
  // substring.
  int maxLength = INT_MIN;
  int windowStart = 0;

  // Iterate through the string.
  for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd) {
    // Increment the count of the current character.
    hm[str[windowEnd]]++;

    // While the substring contains more than K distinct characters, shrink the
    // substring.
    while (hm.size() > k) {
      // Decrement the count of the character at the start of the substring.
      hm[str[windowStart]]--;

      // If the count of the character at the start of the substring becomes
      // zero, remove it from the hash map.
      if (hm[str[windowStart]] == 0) {
        hm.erase(str[windowStart]);
      }

      // Move the start of the substring to the right.
      windowStart++;
    }

    // Update the maximum length if the current substring length is greater.
    maxLength = max(maxLength, windowEnd - windowStart + 1);
  }

  // Return the maximum length.
  return maxLength;
}

int main() {
  string str;
  getline(cin, str);
  int k;
  cin >> k;
  int maxLength = findLength(str, k);
  cout << maxLength;
  return 0;
}