#include <iostream>
using namespace std;

void replaceChars(char s[], char c) {
  if (s[0] == '\0') {
    return;
  }
  if (s[0] == c) {
    s[0] = 'x';
  }
  replaceChars(s + 1, c);
}

int main() {
  char s[100];
  cin >> s;

  replaceChars(s, 'b');

  cout << s;

  return 0;
}