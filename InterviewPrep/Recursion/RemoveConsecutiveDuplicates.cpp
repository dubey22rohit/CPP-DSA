#include <iostream>
using namespace std;

void removeDuplicates(char s[]) {
  if (s[0] == '\0') {
    return;
  }
  if (s[0] != s[1]) {
    removeDuplicates(s + 1);
  } else {
    int i = 1;
    for (; s[i] != '\0'; ++i) {
      s[i - 1] = s[i];
    }
    s[i - 1] = s[i];
    removeDuplicates(s);
  }
}

int main() {
  char s[100];
  cin >> s;

  removeDuplicates(s);

  cout << s;
  return 0;
}