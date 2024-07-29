#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * Checks if two strings are anagrams of each other.
 *
 * @param s The first string.
 * @param t The second string.
 *
 * @return True if the strings are anagrams, false otherwise.
 */
bool isAnagram(string s, string t) {
  // Check if the strings have different lengths.
  if (s.size() != t.size()) {
    return false;
  }

  // Create two unordered maps to store the frequency of each character in the
  // strings.
  unordered_map<int, int> shm;
  unordered_map<int, int> thm;

  // Iterate through each character in the strings and increment its frequency
  // in the respective maps.
  for (int i = 0; i < s.size(); ++i) {
    shm[s[i]]++;
    thm[t[i]]++;
  }

  // Check if the frequencies of each character in the maps are the same.
  // If they are not, the strings are not anagrams.
  for (int i = 0; i < shm.size(); ++i) {
    if (shm[i] != thm[i]) {
      return false;
    }
  }

  // If all the checks pass, the strings are anagrams.
  return true;
}

int main() {
  string s = "anagram", t = "nagaram";
  cout << isAnagram(s, t);
  return 0;
}