#include <iostream>
#include <vector>
using namespace std;

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