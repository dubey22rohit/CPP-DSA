#include <iostream>
#include <unordered_map>
using namespace std;

// No-repeat Substring (hard)
// Given a string, find the length of the longest substring which has no
// repeating characters.

/**
 * @brief Finds the length of the longest substring in a given string that has
 * no repeating characters.
 *
 * @param str The input string.
 * @return The length of the longest substring without repeating characters.
 */
int findLength(const string &str) {
  // Create a hash map to store the index of the rightmost occurrence of each
  // character in the substring.
  unordered_map<char, int> hm;

  // Initialize variables to track the maximum length and the start of the
  // substring.
  int maxLength = INT_MIN, windowStart = 0;

  // Iterate through the string.
  for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd) {
    // Get the rightmost character of the current window.
    char rightChar = str[windowEnd];

    // If the rightmost character is already present in the substring, move the
    // start of the window to the right of the rightmost occurrence of the
    // character.
    if (hm.find(rightChar) != hm.end()) {
      windowStart = max(windowStart, hm[rightChar] + 1);
    }

    // Update the index of the rightmost occurrence of the character in the
    // substring.
    hm[rightChar] = windowEnd;

    // Update the maximum length if the current window length is greater.
    maxLength = max(maxLength, windowEnd - windowStart + 1);
  }

  // Return the maximum length.
  return maxLength;
}

int main() {
  string str;
  getline(cin, str);
  int maxLength = findLength(str);
  cout << maxLength;
  return 0;
}
