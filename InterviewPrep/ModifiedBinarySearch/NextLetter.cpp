#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of lowercase letters sorted in ascending order, find the smallest
letter in the given array greater than a given ‘key’.

Assume the given array is a circular list, which means that the last letter is
assumed to be connected with the first letter. This also means that the smallest
letter in the given array is greater than the last letter of the array and is
also the first letter of the array.

Write a function to return the next letter of the given ‘key’.
*/

char searchNextLetter(vector<char>& letters, char key) {
  int n = letters.size();
  if (key < letters[0] || key > letters[n - 1]) {
    return letters[0];
  }

  int start = 0, end = n - 1;
  int mid;

  while (start <= end) {
    mid = start + (end - start) / 2;
    if (key < letters[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return letters[start % n];
}

int main() {
  vector<char> letters{'a', 'c', 'f', 'h'};
  cout << searchNextLetter(letters, 'b');
  return 0;
}