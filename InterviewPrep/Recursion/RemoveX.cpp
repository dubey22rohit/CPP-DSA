#include <iostream>
#include <string>
using namespace std;

void removeX(char input[]) {
  if (input[0] == '\0') {
    return;
  }
  if (input[0] != 'x') {
    removeX(input + 1);
  } else {
    int i = 1;
    for (; input[i] != '\0'; ++i) {
      input[i - 1] = input[i];
    }
    input[i - 1] = input[i];
    removeX(input);
  }
}

int main() {
  char input[100];
  cin >> input;
  removeX(input);
  cout << input;

  return 0;
}