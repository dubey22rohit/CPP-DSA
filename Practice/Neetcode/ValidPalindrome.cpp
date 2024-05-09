#include <cctype>
#include <iostream>
using namespace std;

bool isPalindrome(string s) {
  int i = 0, j = s.size() - 1;
  while (i < j) {
    while (!isalnum(s[i]) && i < j) {
      i++;
    }
    while (!isalnum(s[j]) && i < j) {
      j--;
    }
    if (tolower(s[i]) != tolower(s[j])) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

int main() {
  string s;
  getline(cin, s);
  cout << isPalindrome(s);
  return 0;
}
