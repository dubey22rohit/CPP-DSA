#include <iostream>
using namespace std;

/**
 * Checks if a given string is a palindrome.
 *
 * @param s The string to check.
 *
 * @return True if the string is a palindrome, false otherwise.
 */
bool isPalindrome(string s) {
  int i = 0, j = s.size() - 1;

  /**
   * Iterate through the string and compare the characters at the current
   * position with the ones at the mirrored position.
   */
  while (i <= j) {
    /**
     * If the character at the current position is not alphanumeric,
     * increment the current position.
     */
    while (!isalnum(s[i]) && i < j) {
      i++;
    }
    /**
     * If the character at the mirrored position is not alphanumeric,
     * decrement the mirrored position.
     */
    while (!isalnum(s[j]) && j > i) {
      j--;
    }
    /**
     * If the characters at the current position and the mirrored position
     * are not equal, the string is not a palindrome.
     */
    if (tolower(s[i]) != tolower(s[j])) {
      return false;
    }
    /**
     * Move to the next position and the mirrored position.
     */
    i++;
    j--;
  }
  /**
   * If all characters match, the string is a palindrome.
   */
  return true;
}

int main() {
  string s;
  getline(cin, s);
  cout << isPalindrome(s);
  return 0;
}